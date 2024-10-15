import scrapy
from real_estate.items import RealEstateItem
from datetime import datetime, timedelta


class LianjiaSpider(scrapy.Spider):
    name = "lianjia_spider"
    allowed_domains = ["xm.lianjia.com"]
    start_urls = ["https://xm.lianjia.com/ershoufang/"]

    custom_settings = {
        "DEFAULT_REQUEST_HEADERS": {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
        },
        "RETRY_ENABLED": True,
        "RETRY_TIMES": 10,  # Number of retries
        "DOWNLOAD_TIMEOUT": 15,  # Increase timeout
        "DOWNLOADER_MIDDLEWARES": {
            "scrapy.downloadermiddlewares.retry.RetryMiddleware": 90,
            "scrapy_user_agents.middlewares.RandomUserAgentMiddleware": 400,
            "scrapy.downloadermiddlewares.httpproxy.HttpProxyMiddleware": 110,
        },
        "HTTPPROXY_ENABLED": True,
        "HTTPPROXY_PROXY": "http://127.0.0.1:7890",  # Your proxy address
    }

    def start_requests(self):
        # Define the number of pages to scrape
        total_pages = 30  # Change this value based on the number of pages available
        base_url = "https://xm.lianjia.com/ershoufang/pg{}"

        # Start with the first page
        yield scrapy.Request("https://xm.lianjia.com/ershoufang/", callback=self.parse)

        # Generate URLs for subsequent pages
        for page in range(2, total_pages + 1):
            url = base_url.format(page)
            yield scrapy.Request(url, callback=self.parse)

    def parse(self, response):
        listings = response.css("li.clear.LOGCLICKDATA")
        for listing in listings:
            item = RealEstateItem()
            item["name"] = listing.css("div.title a::text").get().strip()
            item["address"] = listing.css("div.positionInfo a::text").getall()
            item["price"] = listing.css("div.totalPrice span::text").get() + "万"
            item["area"] = listing.css("div.houseInfo::text").re_first(
                r"(\d+\.?\d*)平米"
            )
            item["house_type"] = listing.css("div.houseInfo::text").re_first(
                r"(\d+室\d+厅)"
            )

            # Extract and format the publish date
            publish_date_raw = listing.css("div.followInfo::text").re_first(
                r"(\d+)个月以前发布"
            )
            if publish_date_raw:
                months_ago = int(publish_date_raw)
                publish_date = datetime.now() - timedelta(days=30 * months_ago)
                item["publish_date"] = publish_date.strftime("%Y.%m")
            else:
                item["publish_date"] = "Unknown"

            yield item

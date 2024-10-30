import scrapy


class RealEstateItem(scrapy.Item):
    name = scrapy.Field()
    address = scrapy.Field()
    price = scrapy.Field()
    area = scrapy.Field()
    house_type = scrapy.Field()
    publish_date = scrapy.Field()

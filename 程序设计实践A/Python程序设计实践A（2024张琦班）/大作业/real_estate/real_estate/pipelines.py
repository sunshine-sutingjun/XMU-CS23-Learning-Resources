import sqlite3


class RealEstatePipeline:

    def open_spider(self, spider):
        self.connection = sqlite3.connect("real_estate.db")
        self.cursor = self.connection.cursor()
        self.cursor.execute(
            """
            CREATE TABLE IF NOT EXISTS listings (
                id INTEGER PRIMARY KEY,
                name TEXT,
                address TEXT,
                price TEXT,
                area TEXT,
                house_type TEXT,
                publish_date TEXT
            )
        """
        )
        self.connection.commit()

    def close_spider(self, spider):
        self.connection.close()

    def process_item(self, item, spider):
        self.cursor.execute(
            """
            INSERT INTO listings (name, address, price, area, house_type, publish_date) VALUES (?, ?, ?, ?, ?, ?)
        """,
            (
                item.get("name"),
                ", ".join(item.get("address", [])),
                item.get("price"),
                item.get("area"),
                item.get("house_type"),
                item.get("publish_date"),
            ),
        )
        self.connection.commit()
        return item

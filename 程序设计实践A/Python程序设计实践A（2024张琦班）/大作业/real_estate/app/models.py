from app import db


class Listing(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    address = db.Column(db.String(100))
    price = db.Column(db.String(20))
    area = db.Column(db.Float)
    house_type = db.Column(db.String(20))
    publish_date = db.Column(db.String(20))

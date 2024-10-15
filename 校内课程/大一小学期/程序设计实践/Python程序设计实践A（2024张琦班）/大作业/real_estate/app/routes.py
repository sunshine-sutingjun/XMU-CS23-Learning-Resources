from flask import render_template, request
from app import app
import sqlite3
import pandas as pd
from data_process_analysis.data_process_analysis import generate_plots

DATABASE_PATH = "real_estate.db"


def get_listings(filters=None, sort_by=None, sort_order="asc"):
    conn = sqlite3.connect(DATABASE_PATH)
    query = "SELECT * FROM listings"
    params = []

    if filters:
        conditions = []
        if "name" in filters:
            conditions.append("name LIKE ?")
            params.append(f"%{filters['name']}%")
        if "address" in filters:
            conditions.append("address LIKE ?")
            params.append(f"%{filters['address']}%")
        if "min_price" in filters:
            conditions.append("CAST(price AS REAL) >= ?")
            params.append(filters["min_price"])
        if "max_price" in filters:
            conditions.append("CAST(price AS REAL) <= ?")
            params.append(filters["max_price"])
        if "min_area" in filters:
            conditions.append("CAST(area AS REAL) >= ?")
            params.append(filters["min_area"])
        if "max_area" in filters:
            conditions.append("CAST(area AS REAL) <= ?")
            params.append(filters["max_area"])
        if "house_type" in filters and filters["house_type"]:
            conditions.append("house_type = ?")
            params.append(filters["house_type"])

        if conditions:
            query += " WHERE " + " AND ".join(conditions)

    if sort_by:
        query += f" ORDER BY {sort_by} {sort_order.upper()}"

    print("Filters:", filters)
    print("Query:", query)
    print("Params:", params)

    df = pd.read_sql_query(query, conn, params=params)
    conn.close()
    return df


def get_unique_house_types():
    conn = sqlite3.connect(DATABASE_PATH)
    query = "SELECT DISTINCT house_type FROM listings"
    df = pd.read_sql_query(query, conn)
    conn.close()
    return df["house_type"].tolist()


@app.route("/")
def index():
    filters = {
        "name": request.args.get("name"),
        "address": request.args.get("address"),
        "min_price": request.args.get("min_price"),
        "max_price": request.args.get("max_price"),
        "min_area": request.args.get("min_area"),
        "max_area": request.args.get("max_area"),
        "house_type": request.args.get("house_type"),
    }
    filters = {k: v for k, v in filters.items() if v is not None and v != ""}

    sort_by = request.args.get("sort_by")
    sort_order = request.args.get("sort_order", "asc")

    listings = get_listings(filters, sort_by, sort_order)
    house_types = get_unique_house_types()
    return render_template(
        "index.html",
        listings=listings.to_dict(orient="records"),
        filters=filters,
        sort_by=sort_by,
        sort_order=sort_order,
        house_types=house_types,
    )


@app.route("/listing/<int:id>")
def listing(id):
    conn = sqlite3.connect(DATABASE_PATH)
    listing = pd.read_sql_query("SELECT * FROM listings WHERE id=?", conn, params=(id,))
    conn.close()
    if listing.empty:
        return "Listing not found", 404
    return render_template("listing.html", listing=listing.iloc[0].to_dict())


@app.route("/analysis")
def analysis():
    generate_plots()
    price_plot_url = "/static/analysis_output/price_distribution.png"
    area_plot_url = "/static/analysis_output/area_distribution.png"
    region_plot_url = "/static/analysis_output/region_counts.png"
    return render_template(
        "analysis.html",
        price_plot_url=price_plot_url,
        area_plot_url=area_plot_url,
        region_plot_url=region_plot_url,
    )

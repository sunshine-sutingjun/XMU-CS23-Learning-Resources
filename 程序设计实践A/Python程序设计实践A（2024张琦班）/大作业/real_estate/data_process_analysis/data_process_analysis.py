import sqlite3
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
import os

# Constants
DATABASE_PATH = "real_estate.db"
OUTPUT_DIR = "app/static/analysis_output"
FONT_PATH = "C:/Windows/Fonts/simhei.ttf"  # Path to SimHei font on Windows


def load_data(database_path):
    """Load data from the SQLite database."""
    conn = sqlite3.connect(database_path)
    df = pd.read_sql_query("SELECT * FROM listings", conn)
    conn.close()
    return df


def clean_data(df):
    """Clean and transform the data."""
    df["price"] = df["price"].str.replace("万", "").astype(float)
    df["area"] = df["area"].astype(float)
    df["region"] = df["address"].apply(lambda x: x.split(" , ")[-1])
    df.dropna(inplace=True)
    return df


def analyze_data(df):
    """Perform statistical analysis on the data."""
    price_stats = df["price"].describe()
    area_stats = df["area"].describe()
    region_counts = df["region"].value_counts()
    return price_stats, area_stats, region_counts


def plot_histogram(data, title, xlabel, ylabel, output_path, font_prop):
    """Plot and save a histogram."""
    plt.figure(figsize=(12, 6))
    plt.hist(data, bins=30, color="blue", alpha=0.7)
    plt.title(title, fontproperties=font_prop)
    plt.xlabel(xlabel, fontproperties=font_prop)
    plt.ylabel(ylabel, fontproperties=font_prop)
    plt.savefig(output_path)
    plt.close()


def plot_bar_chart(data, title, xlabel, ylabel, output_path, font_prop):
    """Plot and save a bar chart."""
    plt.figure(figsize=(12, 6))
    data.plot(kind="bar", color="purple", alpha=0.7)
    plt.title(title, fontproperties=font_prop)
    plt.xlabel(xlabel, fontproperties=font_prop)
    plt.ylabel(ylabel, fontproperties=font_prop)
    plt.savefig(output_path)
    plt.close()


def create_plots(df, output_dir, font_path):
    """Create and save plots."""
    # Set up font properties
    font_prop = fm.FontProperties(fname=font_path)
    plt.rcParams["font.family"] = font_prop.get_name()

    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Plotting configuration
    plt.style.use("ggplot")

    # Price Distribution Histogram
    plot_histogram(
        df["price"],
        "Price Distribution",
        "Price (in ten thousands)",
        "Frequency",
        os.path.join(output_dir, "price_distribution.png"),
        font_prop,
    )

    # Area Distribution Histogram
    plot_histogram(
        df["area"],
        "Area Distribution",
        "Area (in square meters)",
        "Frequency",
        os.path.join(output_dir, "area_distribution.png"),
        font_prop,
    )

    # Region Counts Bar Chart
    region_counts = df["region"].value_counts()
    plot_bar_chart(
        region_counts,
        "Number of Listings per Region",
        "Region",
        "Number of Listings",
        os.path.join(output_dir, "region_counts.png"),
        font_prop,
    )


def generate_plots():
    # Load and clean data
    df = load_data(DATABASE_PATH)
    df = clean_data(df)

    # Analyze data
    price_stats, area_stats, region_counts = analyze_data(df)

    # Print statistics
    print("Price Statistics:\n", price_stats)
    print("Area Statistics:\n", area_stats)
    print("Region Counts:\n", region_counts)

    # Create and save plots
    create_plots(df, OUTPUT_DIR, FONT_PATH)

def main():
    generate_plots()

if __name__=="__main__":
    main()
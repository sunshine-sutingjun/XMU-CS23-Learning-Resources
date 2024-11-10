import os
import shutil
from bs4 import BeautifulSoup

# 定义基础文件夹路径
base_folder = "../website_copy"  # 修改为当前的文件夹路径
source_folder = os.path.join(base_folder, "厦门大学本科教育教学审核评估网_files")
html_file = os.path.join(base_folder, "厦门大学本科教育教学审核评估网.html")

# 定义目标文件夹
css_folder = os.path.join(base_folder, "css")
js_folder = os.path.join(base_folder, "js")
img_folder = os.path.join(base_folder, "images")

# 创建目标文件夹
os.makedirs(css_folder, exist_ok=True)
os.makedirs(js_folder, exist_ok=True)
os.makedirs(img_folder, exist_ok=True)

# 读取 HTML 文件内容
with open(html_file, "r", encoding="utf-8") as f:
    soup = BeautifulSoup(f, "html.parser")

# 处理 CSS 文件
for link in soup.find_all("link", {"rel": "stylesheet"}):
    href = link.get("href")
    if href and href.startswith("./厦门大学本科教育教学审核评估网_files/"):
        css_filename = os.path.basename(href)
        css_source_path = os.path.join(source_folder, css_filename)
        css_dest_path = os.path.join(css_folder, css_filename)

        # 如果文件存在，移动文件并修改路径
        if os.path.exists(css_source_path):
            shutil.move(css_source_path, css_dest_path)
            link["href"] = os.path.join("css", css_filename)

# 处理 JS 文件
for script in soup.find_all("script", {"src": True}):
    src = script.get("src")
    if src and src.startswith("./厦门大学本科教育教学审核评估网_files/"):
        js_filename = os.path.basename(src)
        js_source_path = os.path.join(source_folder, js_filename)
        js_dest_path = os.path.join(js_folder, js_filename)

        # 如果文件存在，移动文件并修改路径
        if os.path.exists(js_source_path):
            shutil.move(js_source_path, js_dest_path)
            script["src"] = os.path.join("js", js_filename)

# 处理图片文件
for img in soup.find_all("img"):
    src = img.get("src")
    if src and src.startswith("./厦门大学本科教育教学审核评估网_files/"):
        img_filename = os.path.basename(src)
        img_source_path = os.path.join(source_folder, img_filename)
        img_dest_path = os.path.join(img_folder, img_filename)

        # 如果文件存在，移动文件并修改路径
        if os.path.exists(img_source_path):
            shutil.move(img_source_path, img_dest_path)
            img["src"] = os.path.join("images", img_filename)

# 保存修改后的 HTML 文件
new_html_file = os.path.join(base_folder, "index.html")
with open(new_html_file, "w", encoding="utf-8") as f:
    f.write(str(soup))

print("文件已成功分离并更新路径。")

"""
Flask 应用程序的路由和错误处理示例

此 Flask 应用程序展示了以下功能：
1. 根路由 ("/") 返回 "Hello, World!"。
2. 动态路由 ("/user/<username>") 返回 "User: {username}"。
3. 路由 ("/submit") 处理 GET 和 POST 请求：
   - GET 请求返回一个表单页面。
   - POST 请求处理表单提交并返回 "Form submitted!"。
4. 处理 404 错误，当访问不存在的页面时返回 "Page not found"。

使用方法：
1. 如果还没有安装 Flask，请先安装：pip install flask
2. 运行此脚本：python <filename>.py
3. 在您的网页浏览器中访问应用程序： http://127.0.0.1:5000/

路由：
- http://127.0.0.1:5000/ : 返回 "Hello, World!"
- http://127.0.0.1:5000/user/<username> : 返回 "User: {username}"
- http://127.0.0.1:5000/submit : GET 请求返回一个表单，POST 请求返回 "Form submitted!"
"""

from flask import Flask, request, render_template_string

app = Flask(__name__)


# 根 URL 路由
@app.route("/")
def home():
    """
    根 URL 路由。
    返回 "Hello, World!"。
    """
    return "Hello, World!"


# 动态 URL 路由，显示用户名
@app.route("/user/<username>")
def show_user(username):
    """
    动态路由，接收 URL 参数中的用户名。
    返回 "User: {username}"。
    """
    return f"User: {username}"


# 处理 GET 和 POST 请求的路由
@app.route("/submit", methods=["GET", "POST"])
def submit_form():
    """
    处理 GET 和 POST 请求的路由。
    - GET 请求返回表单页面。
    - POST 请求处理表单提交并返回 "Form submitted!"。
    """
    if request.method == "POST":
        return "Form submitted!"
    return render_template_string(
        """
        <form method="post">
            <input type="submit" value="提交">
        </form>
    """
    )


# 处理 404 错误的函数
@app.errorhandler(404)
def page_not_found(e):
    """
    自定义 404 错误处理函数。
    返回 "Page not found"。
    """
    return "Page not found", 404


if __name__ == "__main__":
    # 运行 Flask 应用程序
    app.run(debug=True)

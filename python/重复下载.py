request_urls = [
    "https://acg.toubiec.cn/random"
]


def down_load(url, request_max=3):
    print("正在请求的URL是：", url)
    result_html = ""
    result_status_code = ""
    try:
        result = session.get(url=url)
        result_html = result.content
        result_status_code = result.status_code
        print(result_status_code)
    except Exception as e:
        print(e)
        if request_max > 0:
            if result_status_code != 200:
                return down_load(url, request_max-1)
    return result_html


for url in request_urls:
    down_load(url=url, request_max=13)

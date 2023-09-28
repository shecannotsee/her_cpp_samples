import re
import sys


def update_chapter_numbers(filename):
    # 初始化chapter_number为1
    chapter_number = 1
    # 初始化buffer为空字符串
    buffer = ""

    try:
        # 打开文件进行读取
        with open(filename, 'r', encoding='utf-8') as file:
            for line in file:
                # 使用正则表达式查找格式为#### (任何内容)的行
                match = re.search(r'#### \((\d+)\)', line)
                if match:
                    # 找到匹配项，将括号内的数字替换为chapter_number
                    line = re.sub(r'#### \(\d+\)', f'#### ({chapter_number})', line)
                    # 增加chapter_number的值
                    chapter_number += 1
                # 将修改后的行添加到buffer中
                buffer += line

    except FileNotFoundError:
        print(f"文件 '{filename}' 不存在.")
        return

    try:
        # 打开文件进行写入（覆盖原文件）
        with open(filename, 'w', encoding='utf-8') as file:
            file.write(buffer)

        print(f"文件 '{filename}' 修改完成.")
    except Exception as e:
        print(f"修改文件时出错: {str(e)}")
# def update_chapter_numbers(filename):


if __name__ == "__main__":
    update_chapter_numbers("README.md")
    update_chapter_numbers("README_ZH.md")
    print("文件中的章节号已更新完成。")

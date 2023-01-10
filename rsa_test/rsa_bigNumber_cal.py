import argparse

def rsa_bigNumber_cal(arg_1,arg_2,arg_3):
    # 去掉多余的换行符
    print(pow(arg_1,arg_2)%arg_3,end='')

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("arg_1", type=int)
    parser.add_argument("arg_2", type=int)
    parser.add_argument("arg_3", type=int)
    args = parser.parse_args()
    rsa_bigNumber_cal(args.arg_1, args.arg_2, args.arg_3)

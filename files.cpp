#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iostream>
 
void dofile(char *in_fname,char *pwd,char *out_fname);/*对文件进行加密的具体函数*/

/*定义main()函数的命令行参数*/
int main(int argc,char *argv[]){
    printf("使用指南（加密解密均使用该软件）：\n");
    printf("小明有一个文件 yuan_shi_wen_jian.mp4 需要加密。\n");
    printf("首先他输入 yuan_shi_wen_jian.mp4\n");
    printf("然后他输入加密密码123456\n");
    printf("然后他输入加密后的文件名 jia_mi_hou_wen_jian.mp4\n");
    printf("小红获得加密后文件之后，输入文件名 jia_mi_hou_wen_jian.mp4\n");
    printf("然后输入和小明约定好的加密解密密码123456n");
    printf("然后生成解密后的文件，也就是小明最开始的源文件 xiao_hong.mp4\n");
    printf("最后小红获得最开始的文件“yuan_shi_wen_jian.mp4”\n");
    printf("\n\n");

    char in_fname[30];/*用户输入的要加密的文件名*/
    char out_fname[30];
    char pwd[8];/*用来保存密码*/
    
    if(argc!=4){/*容错处理*/
        printf("请输入要加密（解密）的文件名（最好与程序放在用一个目录下，并且加上文件的后缀，文件名不要超过三十个字）：");
        //printf("In-fname:");
        std::cin>>in_fname;/*得到要加密的文件名*/
        
        printf("请输入加密密码（不超过八位）：");
        //printf("Password:");
        std::cin>>pwd;/*得到密码*/
        
        printf("请输入生成的文件名：");
        //printf("Out-file:");
        std::cin>>out_fname;/*得到加密后你要的文件名*/
        
        
        dofile(in_fname,pwd,out_fname);
    }   
    else{/*如果命令行参数正确,便直接运行程序*/
        strcpy(in_fname,argv[1]);
        strcpy(pwd,argv[2]);
        strcpy(out_fname,argv[3]);
        dofile(in_fname,pwd,out_fname);
    }
}
 
 
/*加密子函数开始*/
void dofile(char *in_fname,char *pwd,char *out_file){
    FILE *fp1,*fp2;
    register char ch;
    int j=0;
    int j0=0;
    
    fp1=fopen(in_fname,"rb");
    if(fp1==NULL){
        printf("打不开软件./n"); 
        //printf("cannot open in-file./n");   
        exit(1);/*如果不能打开要加密的文件,便退出程序*/
    }
    fp2=fopen(out_file,"wb");
    if(fp2==NULL){
        printf("不能建立加密后的文件./n"); 
        //printf("cannot open or create out-file./n");
        exit(1);/*如果不能建立加密后的文件,便退出*/
    }
    while(pwd[++j0]);
    ch=fgetc(fp1);
    
    /*加密算法开始*/
    while(!feof(fp1)){
        fputc(ch^pwd[j>=j0?j=0:j++],fp2);/*异或后写入fp2文件*/
        ch=fgetc(fp1);
    }
    fclose(fp1);/*关闭源文件*/
    fclose(fp2);/*关闭目标文件*/
}
 
/*程序结束*/
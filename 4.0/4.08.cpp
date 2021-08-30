//验证ip地址
#include <stdio.h>          //头文件
int judge(char *num, int n) //判断函数，调用时判断单个ip地址是否满足在0~255之间。num数组传入的是单个ip地址，n为num数组的位数
{
    int i; //i的作用是将num数组中的多个数复原为一个整型的单个ip地址
    if (n == 1)
    {
        i = *num - '0';
        if (i >= 0 && i <= 9)
        {
            return 1;
        }
        else
            return 0;
    }
    else if (n == 2)
    {
        if ((*num - '0') == 0)
            return 0;
        i = (*(num + 1) - '0') + (*num - '0') * 10;
        if (i >= 10 && i < 100)
            return 1;
        else
            return 0;
    }
    else if (n == 3)
    {
        if ((*num - '0') == 0)
            return 0;
        i = (*(num + 2) - '0') + (*(num + 1) - '0') * 10 + (*num - '0') * 100;
        if (i >= 100 && i <= 255)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int  main() //主函数
{
    char ip[20];
    char num[3];
    int i = 0, L = 0, k = 0, n = 0, y, p, o, b = 0;
    printf("请输入IP地址：");
    scanf("%s", ip);
    for (o = 0; ip[o] != '\0'; o++) //计算单个ip地址的位数，1位、2位或者3位
        L++;
    ip[L] = '\0'; //将判断数字位数后的ip地址截断，只保留每一位的数字
    for (i; i <= L; i++)
    {
        p = ip[i] - '0'; //ip[i]为一个字符型数，**ip[i]-'0'是将ip[i]里的字符型改为整型**例如ip[i]为char型'9'通过后变成int型9
        if (p >= 0 && p <= 9)
        {                   //判断提出的每一位ip单个字符里的数是否为0~9
            num[k] = ip[i]; //通过循环将ip地址的单个数值赋给num数组，则num数组内存储的就是单个0~255的值
            k++;
        }
        else if (ip[i] == '.' || ip[i] == '\0')
        {        //判断若读取到'.'或者结束标准则给num数组加上个接收点，锁定num数组的值
            b++; //统计调用判断函数的次数
            num[k] = '\0';
            y = judge(num, k); //通过judge函数判断每一位ip地址是否满足条件，满足返回1，不满足返回0
            n = n + y;         //使用n计算返回的1的个数
            k = 0;
        }
        else
        { //如果的判断ip地址的单个值不是0~9、'.'或者'\0'这三个字符，直接将n清零
            n = 0;
            break;
        }
    }
    if (n == 4 && b == 4) //若恰好调用4次判断函数，且每一次都正确返回1，则ip地址正确
        printf("IP地址正确");
    else
        printf("IP地址不正确");
    getchar(); //防止运行后窗口退出，无法查看结果。等同于按任意键结束
    getchar();
}

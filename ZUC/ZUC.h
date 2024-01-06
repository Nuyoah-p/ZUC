#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h> 

/* 定义LFSR */
unsigned int LFSR_S0;
unsigned int LFSR_S1; //区分S盒的记号
unsigned int S2;
unsigned int S3;
unsigned int S4;
unsigned int S5;
unsigned int S6;
unsigned int S7;
unsigned int S8;
unsigned int S9;
unsigned int S10;
unsigned int S11;
unsigned int S12;
unsigned int S13;
unsigned int S14;
unsigned int S15;

/* R1和R2 */
unsigned int R1;
unsigned int R2;

/* BR层X0 X1 X2 X3 */
unsigned int X0;
unsigned int X1;
unsigned int X2;
unsigned int X3;

/* S盒定义  把一个2位十六进制数写成二进制，然后对半砍分别4个数字
    转成十进制作为行、列，然后在对应的S盒的第x行第y列的数字输出
    比如输入0x99输入LFSR_S0，二进制变成10011001，1001十进制是9，那就取第9行第9列
    如果是0x12345678，那就0x12进去LFSR_S0，0x34进去LFSR_S1,0x56进去LFSR_S0，0x78进去LFSR_S1，最后结果并在一起*/
unsigned char S0[256] = {
    0x3e, 0x72, 0x5b, 0x47, 0xca, 0xe0, 0x00, 0x33, 0x04, 0xd1, 0x54, 0x98, 0x09, 0xb9, 0x6d, 0xcb,
    0x7b, 0x1b, 0xf9, 0x32, 0xaf, 0x9d, 0x6a, 0xa5, 0xb8, 0x2d, 0xfc, 0x1d, 0x08, 0x53, 0x03, 0x90,
    0x4d, 0x4e, 0x84, 0x99, 0xe4, 0xce, 0xd9, 0x91, 0xdd, 0xb6, 0x85, 0x48, 0x8b, 0x29, 0x6e, 0xac,
    0xcd, 0xc1, 0xf8, 0x1e, 0x73, 0x43, 0x69, 0xc6, 0xb5, 0xbd, 0xfd, 0x39, 0x63, 0x20, 0xd4, 0x38,
    0x76, 0x7d, 0xb2, 0xa7, 0xcf, 0xed, 0x57, 0xc5, 0xf3, 0x2c, 0xbb, 0x14, 0x21, 0x06, 0x55, 0x9b,
    0xe3, 0xef, 0x5e, 0x31, 0x4f, 0x7f, 0x5a, 0xa4, 0x0d, 0x82, 0x51, 0x49, 0x5f, 0xba, 0x58, 0x1c,
    0x4a, 0x16, 0xd5, 0x17, 0xa8, 0x92, 0x24, 0x1f, 0x8c, 0xff, 0xd8, 0xae, 0x2e, 0x01, 0xd3, 0xad,
    0x3b, 0x4b, 0xda, 0x46, 0xeb, 0xc9, 0xde, 0x9a, 0x8f, 0x87, 0xd7, 0x3a, 0x80, 0x6f, 0x2f, 0xc8,
    0xb1, 0xb4, 0x37, 0xf7, 0x0a, 0x22, 0x13, 0x28, 0x7c, 0xcc, 0x3c, 0x89, 0xc7, 0xc3, 0x96, 0x56,
    0x07, 0xbf, 0x7e, 0xf0, 0x0b, 0x2b, 0x97, 0x52, 0x35, 0x41, 0x79, 0x61, 0xa6, 0x4c, 0x10, 0xfe,
    0xbc, 0x26, 0x95, 0x88, 0x8a, 0xb0, 0xa3, 0xfb, 0xc0, 0x18, 0x94, 0xf2, 0xe1, 0xe5, 0xe9, 0x5d,
    0xd0, 0xdc, 0x11, 0x66, 0x64, 0x5c, 0xec, 0x59, 0x42, 0x75, 0x12, 0xf5, 0x74, 0x9c, 0xaa, 0x23,
    0x0e, 0x86, 0xab, 0xbe, 0x2a, 0x02, 0xe7, 0x67, 0xe6, 0x44, 0xa2, 0x6c, 0xc2, 0x93, 0x9f, 0xf1,
    0xf6, 0xfa, 0x36, 0xd2, 0x50, 0x68, 0x9e, 0x62, 0x71, 0x15, 0x3d, 0xd6, 0x40, 0xc4, 0xe2, 0x0f,
    0x8e, 0x83, 0x77, 0x6b, 0x25, 0x05, 0x3f, 0x0c, 0x30, 0xea, 0x70, 0xb7, 0xa1, 0xe8, 0xa9, 0x65,
    0x8d, 0x27, 0x1a, 0xdb, 0x81, 0xb3, 0xa0, 0xf4, 0x45, 0x7a, 0x19, 0xdf, 0xee, 0x78, 0x34, 0x60 };

unsigned char S1[256] = {
    0x55, 0xc2, 0x63, 0x71, 0x3b, 0xc8, 0x47, 0x86, 0x9f, 0x3c, 0xda, 0x5b, 0x29, 0xaa, 0xfd, 0x77,
    0x8c, 0xc5, 0x94, 0x0c, 0xa6, 0x1a, 0x13, 0x00, 0xe3, 0xa8, 0x16, 0x72, 0x40, 0xf9, 0xf8, 0x42,
    0x44, 0x26, 0x68, 0x96, 0x81, 0xd9, 0x45, 0x3e, 0x10, 0x76, 0xc6, 0xa7, 0x8b, 0x39, 0x43, 0xe1,
    0x3a, 0xb5, 0x56, 0x2a, 0xc0, 0x6d, 0xb3, 0x05, 0x22, 0x66, 0xbf, 0xdc, 0x0b, 0xfa, 0x62, 0x48,
    0xdd, 0x20, 0x11, 0x06, 0x36, 0xc9, 0xc1, 0xcf, 0xf6, 0x27, 0x52, 0xbb, 0x69, 0xf5, 0xd4, 0x87,
    0x7f, 0x84, 0x4c, 0xd2, 0x9c, 0x57, 0xa4, 0xbc, 0x4f, 0x9a, 0xdf, 0xfe, 0xd6, 0x8d, 0x7a, 0xeb,
    0x2b, 0x53, 0xd8, 0x5c, 0xa1, 0x14, 0x17, 0xfb, 0x23, 0xd5, 0x7d, 0x30, 0x67, 0x73, 0x08, 0x09,
    0xee, 0xb7, 0x70, 0x3f, 0x61, 0xb2, 0x19, 0x8e, 0x4e, 0xe5, 0x4b, 0x93, 0x8f, 0x5d, 0xdb, 0xa9,
    0xad, 0xf1, 0xae, 0x2e, 0xcb, 0x0d, 0xfc, 0xf4, 0x2d, 0x46, 0x6e, 0x1d, 0x97, 0xe8, 0xd1, 0xe9,
    0x4d, 0x37, 0xa5, 0x75, 0x5e, 0x83, 0x9e, 0xab, 0x82, 0x9d, 0xb9, 0x1c, 0xe0, 0xcd, 0x49, 0x89,
    0x01, 0xb6, 0xbd, 0x58, 0x24, 0xa2, 0x5f, 0x38, 0x78, 0x99, 0x15, 0x90, 0x50, 0xb8, 0x95, 0xe4,
    0xd0, 0x91, 0xc7, 0xce, 0xed, 0x0f, 0xb4, 0x6f, 0xa0, 0xcc, 0xf0, 0x02, 0x4a, 0x79, 0xc3, 0xde,
    0xa3, 0xef, 0xea, 0x51, 0xe6, 0x6b, 0x18, 0xec, 0x1b, 0x2c, 0x80, 0xf7, 0x74, 0xe7, 0xff, 0x21,
    0x5a, 0x6a, 0x54, 0x1e, 0x41, 0x31, 0x92, 0x35, 0xc4, 0x33, 0x07, 0x0a, 0xba, 0x7e, 0x0e, 0x34,
    0x88, 0xb1, 0x98, 0x7c, 0xf3, 0x3d, 0x60, 0x6c, 0x7b, 0xca, 0xd3, 0x1f, 0x32, 0x65, 0x04, 0x28,
    0x64, 0xbe, 0x85, 0x9b, 0x2f, 0x59, 0x8a, 0xd7, 0xb0, 0x25, 0xac, 0xaf, 0x12, 0x03, 0xe2, 0xf2 };

/* d的定义，一堆常数，没什么特殊意义 */
unsigned int d[16] = {
    0x44D7, 0x26BC, 0x626B, 0x135E, 0x5789, 0x35E2, 0x7135, 0x09AF,
    0x4D78, 0x2F13, 0x6BC4, 0x1AF1, 0x5E26, 0x3C4D, 0x789A, 0x47AC };

/* 模2^31-1加法
    模运算比较复杂，比如2+5模3，a=0x2=0010,b=0x5=0101,c=a+b=0111
    0111 与 0100=0100不为0，则0111与上0011再+1就是结果，得到0100=4

*/
unsigned int AddM(unsigned int a, unsigned int b)
{
    unsigned int c = a + b;
    if (c & 0x80000000)
        c = (c & 0x7FFFFFFF) + 1;
    return c;
}

/* 循环左移函数
   比如FF00 0000=1111 1111 0000 0000 0000 0000 0000 0000，左移9位全0，右移22位得到
                 0000 0000 0000 0000 0000 1111 1111 1100再与上
                 0111 1111 1111 1111 1111 1111 1111 1111得到
                 0000 0000 0000 0000 0000 1111 1111 1100*/
#define XunHuanZuoYi_1(x, k) ((((x) << k) | ((x) >> (31 - k))) & 0x7FFFFFFF)
#define XunHuanZuoYi_2(a, k) (((a) << k) | ((a) >> (32 - k)))

                 /* LFSR初始模式 */
void LFSRInitial(unsigned int u)
{
    unsigned int f, v;
    f = LFSR_S0;
    v = XunHuanZuoYi_1(LFSR_S0, 8); //这里公式是1+2^8，为何不用考虑1？
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S4, 20);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S10, 21);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S13, 17);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S15, 15);
    f = AddM(f, v);

    if (S15 == 0)
        S15 = 0x7FFFFFFF;

    LFSR_S0 = LFSR_S1;
    LFSR_S1 = S2;
    S2 = S3;
    S3 = S4;
    S4 = S5;
    S5 = S6;
    S6 = S7;
    S7 = S8;
    S8 = S9;
    S9 = S10;
    S10 = S11;
    S11 = S12;
    S12 = S13;
    S13 = S14;
    S14 = S15;
    S15 = u ^ f;
}

/* LFSR工作模式 */
void LFSRWorking()
{
    unsigned int f, v;

    f = LFSR_S0;
    v = XunHuanZuoYi_1(LFSR_S0, 8);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S4, 20);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S10, 21);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S13, 17);
    f = AddM(f, v);

    v = XunHuanZuoYi_1(S15, 15);
    f = AddM(f, v);

    if (S15 == 0)
        S15 = 0x7FFFFFFF;

    LFSR_S0 = LFSR_S1;
    LFSR_S1 = S2;
    S2 = S3;
    S3 = S4;
    S4 = S5;
    S5 = S6;
    S6 = S7;
    S7 = S8;
    S8 = S9;
    S9 = S10;
    S10 = S11;
    S11 = S12;
    S12 = S13;
    S13 = S14;
    S14 = S15;
    S15 = f;
}

/* 比特重组 */
void Bitreorganization()
{
    X0 = ((S15 & 0x7FFF8000) << 1) | (S14 & 0xFFFF);
    X1 = ((S11 & 0xFFFF) << 16) | (S9 >> 15);
    X2 = ((S7 & 0xFFFF) << 16) | (S5 >> 15);
    X3 = ((S2 & 0xFFFF) << 16) | (LFSR_S0 >> 15);
}

/* L1 */
unsigned int L1(unsigned int X)
{
    return (X ^ XunHuanZuoYi_2(X, 2) ^ XunHuanZuoYi_2(X, 10) ^ XunHuanZuoYi_2(X, 18) ^ XunHuanZuoYi_2(X, 24));
}

/* L2 */
unsigned int L2(unsigned int X)
{
    return (X ^ XunHuanZuoYi_2(X, 8) ^ XunHuanZuoYi_2(X, 14) ^ XunHuanZuoYi_2(X, 22) ^ XunHuanZuoYi_2(X, 30));
}

#define MAKEU32(a, b, c, d) (((unsigned int)(a) << 24) | ((unsigned int)(b) << 16) | ((unsigned int)(c) << 8) | ((unsigned int)(d)))

/* F函数定义 */
unsigned int F()
{
    unsigned int W, W1, W2, u, v;
    W = (X0 ^ R1) + R2;
    W1 = R1 + X1;
    W2 = R2 ^ X2;
    u = L1((W1 << 16) | (W2 >> 16));
    v = L2((W2 << 16) | (W1 >> 16));
    R1 = MAKEU32(S0[u >> 24], S1[(u >> 16) & 0xFF], S0[(u >> 8) & 0xFF], S1[u & 0xFF]);
    R2 = MAKEU32(S0[v >> 24], S1[(v >> 16) & 0xFF], S0[(v >> 8) & 0xFF], S1[v & 0xFF]);
    return W;
}

#define MAKEU31(a, b, c) (((unsigned int)(a) << 23) | ((unsigned int)(b) << 8) | (unsigned int)(c))

/* 整个程序的初始化，LFSR到底是怎么来的 */
void Initialization(unsigned char* k, unsigned char* iv)
{
    unsigned int w, i;

    LFSR_S0 = MAKEU31(k[0], d[0], iv[0]);
    LFSR_S1 = MAKEU31(k[1], d[1], iv[1]);
    S2 = MAKEU31(k[2], d[2], iv[2]);
    S3 = MAKEU31(k[3], d[3], iv[3]);
    S4 = MAKEU31(k[4], d[4], iv[4]);
    S5 = MAKEU31(k[5], d[5], iv[5]);
    S6 = MAKEU31(k[6], d[6], iv[6]);
    S7 = MAKEU31(k[7], d[7], iv[7]);
    S8 = MAKEU31(k[8], d[8], iv[8]);
    S9 = MAKEU31(k[9], d[9], iv[9]);
    S10 = MAKEU31(k[10], d[10], iv[10]);
    S11 = MAKEU31(k[11], d[11], iv[11]);
    S12 = MAKEU31(k[12], d[12], iv[12]);
    S13 = MAKEU31(k[13], d[13], iv[13]);
    S14 = MAKEU31(k[14], d[14], iv[14]);
    S15 = MAKEU31(k[15], d[15], iv[15]);

    /* R1 R2的初始化 */
    R1 = 0;
    R2 = 0;
    for (i = 0; i < 32; i++)
    {
        Bitreorganization();
        w = F();
        LFSRInitial(w >> 1);
    }
}

void get_file_info(const char* file_path, char* file_extension, char* file_directory)
{
    const char* last_slash = strrchr(file_path, '\\');
    const char* last_dot = strrchr(file_path, '.');

    // Get file extension
    if (last_dot && last_dot > last_slash)
    {
        strcpy(file_extension, last_dot + 1);
    }
    else
    {
        strcpy(file_extension, "");
    }

    // Get file directory
    if (last_slash)
    {
        strncpy(file_directory, file_path, last_slash - file_path + 1);
        file_directory[last_slash - file_path + 1] = '\0';
    }
    else
    {
        strcpy(file_directory, "");
    }
}

void GenerateKeystream_en(char* ori_file)
{
    int i, j;
    FILE* file;
    unsigned int org_length;
    unsigned int file_length;
    unsigned char* p;
    int KeystreamLen;
    unsigned int* org_dat;

    Bitreorganization();
    F();
    LFSRWorking();

    file = fopen(ori_file, "rb");
    fseek(file, 0, SEEK_END);
    org_length = ftell(file); // ftell函数，给出文件位置指针当前位置相对于文件首的偏移字节数
    file_length = (((org_length + 3) >> 2) << 2);
    fseek(file, 0, SEEK_SET);

    p = (unsigned char*)malloc(file_length);
    fread(p, org_length, 1, file);
    fclose(file);
    if (org_length != file_length)
    {
        for (j = 0; j < (file_length - org_length); j++)
        {
            *(p + org_length + j) = 0;
        }
    }
    KeystreamLen = (file_length >> 2);
    org_dat = (unsigned int*)p;
    for (i = 0; i < KeystreamLen; i++)
    {
        Bitreorganization();
        *(org_dat + i) = (*(org_dat + i)) ^ (F() ^ X3);
        LFSRWorking();
    }

    char extension[10];
    char directory[100];
    get_file_info(ori_file, extension, directory);
    char real_file[100];
    strcpy_s(real_file, directory);
    strcat_s(real_file, _T("encrypt."));
    strcat_s(real_file, extension);

    file = fopen(real_file, "wb");
    fwrite(p, file_length, 1, file);
    fclose(file);
}

void GenerateKeystream_de(char* enc_file)
{
    int i, j;
    FILE* file;
    unsigned int org_length;
    unsigned int file_length;
    unsigned char* p;
    int KeystreamLen;
    unsigned int* org_dat;

    Bitreorganization();
    F();
    LFSRWorking();

    file = fopen(enc_file, "rb");
    fseek(file, 0, SEEK_END);
    org_length = ftell(file); // ftell函数，给出文件位置指针当前位置相对于文件首的偏移字节数
    file_length = (((org_length + 3) >> 2) << 2);
    fseek(file, 0, SEEK_SET);

    p = (unsigned char*)malloc(file_length);
    fread(p, org_length, 1, file);
    fclose(file);
    if (org_length != file_length)
    {
        for (j = 0; j < (file_length - org_length); j++)
        {
            *(p + org_length + j) = 0;
        }
    }
    KeystreamLen = (file_length >> 2);
    org_dat = (unsigned int*)p;
    for (i = 0; i < KeystreamLen; i++)
    {
        Bitreorganization();
        *(org_dat + i) = (*(org_dat + i)) ^ (F() ^ X3);
        LFSRWorking();
    }

    char extension[10];
    char directory[100];
    get_file_info(enc_file, extension, directory);
    char real_file[100];
    strcpy_s(real_file, directory);
    strcat_s(real_file, _T("recovery."));
    strcat_s(real_file, extension);

    file = fopen(real_file, "wb");
    fwrite(p, file_length, 1, file);
    fclose(file);
}

unsigned char openfile(char* filename) {

    char file[MAX_PATH], * fileselect = NULL;
    OPENFILENAME open;
    ZeroMemory(&open, sizeof(OPENFILENAME));
    open.lStructSize = sizeof(OPENFILENAME);
    open.lpstrFile = file;
    open.lpstrFile[0] = '\0';
    open.nMaxFile = MAX_PATH;
    open.lpstrFilter = "文件(*.*)\0*.*\0";
    open.nFilterIndex = 1;
    open.lpstrFileTitle = NULL;
    open.nMaxFileTitle = 0;
    open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    if (GetOpenFileName(&open)) {
        fileselect = open.lpstrFile;
        strcpy_s(filename, strlen(fileselect) + 1, fileselect);
        return 1;
    }
    else {
        return 0;
    }
}

int do_zuc(bool flag)
{
    unsigned char IV[16] = { 0, 2, 3, 2, 1, 2, 3, 2, 4, 4, 2, 4, 3, 3, 4, 3 };
    unsigned char CK[16] = { 12, 4, 5, 8, 7, 5, 1, 6, 5, 8, 7, 12, 4, 5, 12, 8 };

    char ori_file[100];
    char enc_file[100];

    Initialization(CK, IV);

    if (!flag)
    {
        int choice = 0;
        choice = MessageBox(NULL, _T("选择需要加密的文件"), _T("提示"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
        if (choice == 1) {
            openfile(ori_file);
            GenerateKeystream_en(ori_file);
            MessageBox(NULL, _T("生成加密文件encrypt"), _T("提示"), MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
        }
        else {
            return 0;
        }
        //
    }
    else
    {
        int choice = 0;
        choice = MessageBox(NULL, _T("选择需要解密的文件"), _T("提示"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
        if (choice == 1) {
            openfile(enc_file);
            GenerateKeystream_de(enc_file);
            MessageBox(NULL, _T("还原加密文件recovery"), _T("提示"), MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
        }
        else {
            return 0;
        }
        //GenerateKeystream_de(enc_file);
    }

    return 0;
}


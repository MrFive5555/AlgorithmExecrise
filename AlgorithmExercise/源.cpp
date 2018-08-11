#include <cstring>
#include <iostream>

using namespace std;

#define LEN 5//��������������·�鲢��Ŀ
#define MIN -1//�������ݵĿ�����Сֵ

int ls[LEN + 1];//������,ls[0]���ʤ�ߣ������Ű���
int buf[LEN + 1];//��Ŷ�·�鲢��ͷԪ��ֵ,�������һλ��MIN

void adjust(int s, int *buf) {//s����Ҫ������buf���±�
    int t = (s + LEN) / 2;//�õ�s���ڰ���������ĸ��ڵ�
    while (t>0) {//�����븸�ڵ�Աȣ�ֱ���������ĸ��ڵ�
        if (buf[s]>buf[ls[t]]) {//�����ǰ�ڵ�s��ʤ�ߣ����ڸ��ڵ�
            ls[t] ^= s;//����ls[t]��s
            s ^= ls[t];//s��¼ʤ��
            ls[t] ^= s;//���ڵ��¼����
        }
        t /= 2;//�õ�����������һ�����ڵ㣬�����뵱ǰʤ��s�Ƚ�
    }
    ls[0] = s;//���յ�ʤ�߼�¼��ls[0]
}

void build(int *buf) {
    buf[LEN] = MIN;//���һλ��MIN
    for (int i = 0; i<LEN + 1; ++i)
        ls[i] = LEN;//���а�������ʼ��ΪMIN���±�
    for (int i = 0; i<LEN; ++i)
        adjust(i, buf);//���ε���������ɳ�ʼ��
}

int main() {
    //��ʼbuf
    int tmp[5] = { 18,21,16,11,19 };
    memcpy(buf, tmp, LEN * sizeof(int));
    build(buf);
    cout << buf[ls[0]] << endl;//���11

                               //ȡ��11��buf[3]=17
    int tmp1[5] = { 18,21,16,17,19 };
    memcpy(buf, tmp1, LEN * sizeof(int));
    adjust(3, buf);
    cout << buf[ls[0]] << endl;//���16

    return 0;
}
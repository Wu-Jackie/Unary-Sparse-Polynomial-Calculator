#include "calculator.h"
#include <QDebug>

string qstr2str(const QString qstr){
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}

//初始化
calculator::calculator(){
    Aa->next=nullptr;
    Bb->next=nullptr;
    Cc->next=nullptr;
}

void calculator::clear(){
    quick(Aa);
    quick(Bb);
    quick(Cc);
}

void calculator::quick(polynomial *Ac){
    polynomial *p,*q;
    p=Ac;
    while (p->next!=nullptr){
        q=p->next;
        p->next=q->next;
        free(q);
    }
    Ac->next=nullptr;
}

//检查输入内容
bool calculator::check(QString strr){
    char str[MAX];//接受一个QString类型的参数 strr
    string strA = qstr2str(strr);
    strcpy(str,strA.c_str());
    int i =0;
    if(*str=='^'||*str=='.'){
        return false;
    }
    while (*(str+i)){
        if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='.'||*(str+i)=='^'){//检查是否有相邻的运算符或.
            i++;
            if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='.'||*(str+i)=='^'){
               return false;
            }
        }
        if(*(str+i)=='x'){
            i++;
            //如果出现 'x'，检查其后是否是 '.'、数字（'0' 到 '9'）或者另一个 'x'
            if(*(str+i)=='.'||(*(str+i)>='0'&&*(str+i)<='9')||*(str+i)=='x'){
                return false;
            }
        }
        if(*(str+i)=='.'){
            i++;
            if(*(str+i)<'0'||*(str+i)>'9'){
                return false;
            }
        }
        if(*(str+i)>='0'&&*(str+i)<='9'){
            i++;
            if(*(str+i)=='^') return false;
        }
        i++;
    }
    return true;
}

//输入建立多项式
QString calculator::Build(QString strr , int mp){
    if(mp == 1){
        Aa->next = nullptr;
        int i=0;
        double Coefficient;
        int index = 0;
        char str[MAX];
        string strA = qstr2str(strr);
        strcpy(str,strA.c_str());
        while(*(str+i)){
            Coefficient=Realization(str+i);
            if(*(str+i)!='x'){
                i++;
            }
            while((*(str+i)>='0'&&*(str+i)<='9')||(*(str+i)=='.')){
                i++;
            }
            if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='\0'){
                index=0;
            }else{
                if(*(str+i)=='x'){
                    i++;
                    if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='\0'){
                        index=1;
                    }else{
                        if(*(str+i)=='^'){
                            i++;
                            index=(int)Realization(str+i);
                            while((*(str+i)>='0'&&*(str+i)<='9')||(*(str+i)=='.')){
                                i++;
                            }
                        }
                    }
                }
            }
            push(Aa,Coefficient,index);
            xue(Aa);
        }
        return Formattedoutput(Aa);
    }else{
        Bb->next = nullptr;
        int i=0;
        double Coefficient;
        int index = 0;
        char str[MAX];
        string strA = qstr2str(strr);
        strcpy(str,strA.c_str());
        if(!check(str)) return strr;
        Coefficient=Realization(str+i);
        while(*(str+i)){
            Coefficient=Realization(str+i);
            if(*(str+i)!='x'){
                i++;
            }
            while((*(str+i)>='0'&&*(str+i)<='9')||(*(str+i)=='.')){
                i++;
            }
            if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='\0'){
                index=0;
            }else{
                if(*(str+i)=='x'){
                    i++;
                    if(*(str+i)=='+'||*(str+i)=='-'||*(str+i)=='\0'){
                        index=1;
                    }else if(*(str+i)=='^'){
                        i++;
                        index=(int)Realization(str+i);
                        while((*(str+i)>='0'&&*(str+i)<='9')||(*(str+i)=='.')){
                            i++;
                        }
                    }
                }
            }
            push(Bb,Coefficient,index);
            xue(Bb);
        }
    return Formattedoutput(Bb);
    }
}

//格式化输出
QString calculator::Formattedoutput(polynomial *abc){
    polynomial *p;
    p=abc;
    QString s = "";
    if(p->next==nullptr){
        return s;
    }
    if(p->next->Coefficient == 0){
        s+="0";
        return s;
    }else{
        while(p->next){
            p=p->next;
            if(p->Coefficient == 0){
                if(p->next!= nullptr)
                if(p->next->Coefficient>0){
                    s+="+";
                }
                continue;
            }
            if(p->Coefficient == 1||p->Coefficient == -1){
                if(p->index == 0){
                    s += QString::number(p->Coefficient);
                    continue;
                }
                if(p->Coefficient == -1&& p->index != 0){
                    s += "-";
                }
            }else{
                s+=QString::number(p->Coefficient);
            }
            if(p->index>0){
                s += "x";
                if(p->index>1){
                    s+="^"+QString::number(p->index);
                }
            }
            if(p->next!=nullptr){
                if(p->next->Coefficient>0){
                    s += "+";
                }
            }
        }
        return s;
    }
}

//实现多项式加减
QString calculator::algorithm(int CD){
    polynomial *a=Aa;
    polynomial *b=Bb;
    polynomial *c=Cc;
    quick(Cc);
    if(CD==1){//+
        while(a->next){
            push(c,a->next->Coefficient,a->next->index);a=a->next;
        }
        while(b->next){
            push(c,b->next->Coefficient,b->next->index);b=b->next;
        }
        xue(c);
        return Formattedoutput(c);
    }else if(CD==2){//-
        while(a->next){push(c,a->next->Coefficient,a->next->index);a=a->next;}
        while(b->next){push(c,-(b->next->Coefficient),b->next->index);b=b->next;}
        xue(c);
        return Formattedoutput(c);
    }
}

//直接插入排序
void calculator::sort(polynomial *DLList1){
    polynomial *p,*q,*r;
    polynomial heah;
    p=&heah;
    heah.next=nullptr;
    p=DLList1;
    DLList1->index=0;
    DLList1->Coefficient=0;
    if(p->next==nullptr||p->next->next==nullptr){
        return;
    }
    for(p=p->next->next;p!=nullptr;p=p->next){
        DLList1->index=p->index;
        DLList1->Coefficient=p->Coefficient;
        q=DLList1;
        while(q->next!=p){
            q=q->next;
        }
        while(DLList1->index<q->index){
            q->next->index=q->index;
            q->next->Coefficient=q->Coefficient;
            r=q;
            q=DLList1;
            while(q->next!=r)q=q->next;
        }
        q->next->index=DLList1->index;
        q->next->Coefficient=DLList1->Coefficient;
    }
}

void calculator::del(polynomial *DLList1,double Coefficient,int index)
{
    polynomial *p,*q;
    p=DLList1;
    while(p->next)
    {
        if(p->next->index==index && p->next->Coefficient == Coefficient)
            break;
        p=p->next;
    }
    if(p->next&&p->next->index == index && p->next->Coefficient == Coefficient)
    {
        q=p->next;
        if(q->next)
        {
            p->next=q->next;//p->next存在
        }
        else
        {
            p->next=nullptr;//q->next是nullptr
        }
        free(q);
    }
}

//逆置
void calculator::Inverselist(polynomial *DLList1){
    polynomial *p,*q,*heah;
    heah=DLList1;
    if(heah->next==nullptr||heah->next->next==nullptr){
        return;
    }
    p=heah->next->next;
    heah->next->next=nullptr;
    while(p!=nullptr){
        q=p->next;
        p->next=heah->next;
        heah->next=p;
        p=q;
    }
}

//合并同幂多项式
void calculator::xue(polynomial *head){
    polynomial *p,*q;
    p=head;
    while(p->next){
        q=p->next;
        while(q->next!= nullptr){
            if(p->next->index == q->next->index){
                p->next->Coefficient = q->next->Coefficient+p->next->Coefficient;
                del(head,q->next->Coefficient,q->next->index);
            }else{
                q=q->next;
            }
        }
        p=p->next;
    }
    sort(head);
    Inverselist(head);
}

void calculator::push(polynomial *head,double Coefficient,int index){
    polynomial *L = nullptr;
    polynomial *p = nullptr;
    L = head;
    while (L->next != nullptr){
        L = L->next;
    }
    p = new polynomial;
    p->Coefficient = Coefficient;
    p->index=index;
    p->next = nullptr;
    L->next = p;
}

double calculator::Realization(char *str){
    double s=0.0;
    double d=10.0;
    bool falg=false;
    while(*str==' '){
        str++;
    }
    if(*str=='-'){//记录数字正负
        falg=true;
        str++;
        if(*str=='x'){
            return -1.0;
        }
    }else if((*str=='+'&&*(str+1)=='x')||(*str=='x')){
        return 1.0;
    }if(*str=='+'&&(*(str+1)>='0'&&*(str+1)<='9')){
        str++;
    }if(!(*str>='0'&&*str<='9')){//如果一开始非数字则退出，返回0.0
        return s;
    }
    while(*str>='0'&&*str<='9'&&*str!='.'){//计算小数点前整数部分
        s=s*10.0+*str-'0';
        str++;
    }
    if(*str=='.'){//以后为小数部分
        str++;
    }
    while(*str>='0'&&*str<='9'){//计算小数部分
        s=s+(*str-'0')/d;
        d*=10.0;
        str++;
    }
    return s*(falg?-1.0:1.0);
}

QString calculator::calX(int x,polynomial *head){
   polynomial *p;
   p=head->next;
   double sum=0;
   while(p){
       sum+=p->Coefficient * pow(x,p->index);
       p=p->next;
   }
    QString str=QString::number(sum,'f',2);
    return str;
}

//计算给定值x处多项式表达式的结果
QString calculator::calX1(int i){
    polynomial *c=Cc;
    QString m=calX(i,c);
    return m;
}

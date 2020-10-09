#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const int INF = 0x3f3f3f3f;
const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const long double PI = acos(-1.0);
const double QZERO = 0.000000001;
const double EPS = 1e-9;

typedef long long int lli;
typedef vector<vector<char>> matrix;

typedef struct {int x, y;}Ponto;
typedef struct {Ponto p, q;}Segmento;
Ponto pol[100000], ch[100000]; //vetores globais

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long long a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
}

int Intercepta(Segmento s1, Segmento s2)
{  if ((max(s1.p.x,s1.q.x)>=min(s2.p.x,s2.q.x))&&
       (max(s2.p.x,s2.q.x)>=min(s1.p.x,s1.q.x))&&
       (max(s1.p.y,s1.q.y)>=min(s2.p.y,s2.q.y))&&
       (max(s2.p.y,s2.q.y)>=min(s1.p.y,s1.q.y))&&
       (SentidoPercurso(s1.p,s1.q,s2.p)*SentidoPercurso(s1.p,s1.q,s2.q)<=0)&&
       (SentidoPercurso(s2.p,s2.q,s1.p)*SentidoPercurso(s2.p,s2.q,s1.q)<=0))
       return 1;
    else return 0;     
}

void Quicksort(Ponto *pol, int e, int d)
// O ponto 0 fica fixo na ordena��o, pois tem o menor x
{  int i,j,k;  Ponto t,r;  long long d0, d1, d2;
   if (d > e)
   {  i=e;  j=d;  t=pol[(e+d)/2];
      d1= pol[0].x-t.x;  d2= pol[0].y-t.y;  d0=d1*d1+d2*d2;
      while(i<=j)
      {  while(1)
         {  k=SentidoPercurso(pol[0],pol[i],t);
            if (k==1) i++;
            else if (k==0)
            {  d1= pol[0].x-pol[i].x;  d2= pol[0].y-pol[i].y;  d1= d1*d1+d2*d2;
               if (d1 < d0) i++;
               else break;
            }   
            else break;
         }
         while(1)
         {  k=SentidoPercurso(pol[0],t,pol[j]);
            if (k==1) j--;
            else if (k==0)
            {  d1= pol[0].x-pol[j].x;  d2= pol[0].y-pol[j].y;  d1= d1*d1+d2*d2;
               if (d0 < d1) j--;
               else break;
            }
            else break;
         }  
         if (i<=j) {r=pol[i];  pol[i]=pol[j];  pol[j]=r;  i++; j--;}
      }
      Quicksort(pol, e,j);  Quicksort(pol, i,d);
   }
}   

void OrdenaPontosy(Ponto *pol, int tp)
/*   Ordena pontos por �ngulo, escolhendo como refer�ncia o ponto mais embaixo e mais
   � esquerda. */
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++) 
      if ((pol[i].y < pol[m].y)||(pol[i].y==pol[m].y)&&(pol[i].x<pol[m].x)) m=i;
   p=pol[0];  pol[0]=pol[m];  pol[m]=p;
   Quicksort(pol, 1,tp-1);
}  

int ConvexHull(Ponto *pol, int tp, Ponto *ch, int &tc)
{   int i,j,topo;
    OrdenaPontosy(pol, tp);
    /*Repete o ponto inicial no final*/
    ch[0]= pol[0]; pol[tp]= pol[0];
    j= 1;
    /* Elimina pontos iniciais colineares */
    while (SentidoPercurso(ch[0],pol[j],pol[j+1])==0) j++;
    ch[1]= pol[j];  ch[2]= pol[j+1];
    topo= 2;
    for (i= j+2; i<= tp; i++)
    {   while (SentidoPercurso(ch[topo-1], ch[topo], pol[i]) <= 0) topo--;
        topo++;  ch[topo]= pol[i];
    }
    tc = topo;
    return (topo);
}

int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2){
    if (SentidoPercurso(p0, p1, p2) == 0 &&
        p0.x >= min(p1.x, p2.x) && p0.x <= max(p1.x, p2.x) &&
        p0.y >= min(p1.y, p2.y) && p0.y <= max(p1.y, p2.y))
        return 1;
    return 0;
}

int PontoInterior(Ponto *pol, int n, Ponto q){
	int i, maxx = pol[0].x, cont; Segmento s1, s2;
	pol[n] = pol[0];
	for (i=1; i<=n; i++){
		s1.p = pol[i-1];  s1.q = pol[i];  s2.p=s2.q=q;
		if (Intercepta(s1, s2))
			return 1;
		if (pol[i].x > maxx) maxx = pol[i].x;
	}
	s2.p = q;  s2.q.x = maxx+1;  s2.q.y = q.y;
	cont=0;
	for (i=1; i<=n; i++){
		s1.p = pol[i-1];  s1.q = pol[i];  
		if ((pol[i].y > q.y && pol[i-1].y <= q.y || pol[i-1].y > q.y && pol[i].y <= q.y)
			 && (Intercepta(s1, s2)))
			cont++;
	}	
	return cont%2;
}

int PontoInteriorPoligonoConvexo(Ponto *pol, int n, Ponto q){
	int t1, t2, i; 
	pol[n] = pol[0];
	t1 = SentidoPercurso(q, pol[n-1], pol[0]);
	if (t1 == 0){
		if (PontoNoSegmento(q, pol[n-1], pol[0]))
			return 1;
		return 0;
	}
    for (i=0; i<n-1; i++){
        t2 = SentidoPercurso(q, pol[i], pol[i+1]);
        if (t2 == 0){
			if (PontoNoSegmento(q, pol[n-1], pol[0]))
				return 1;
			return 0; 
		}       
		else if (t2 != t1) return 0;
	}
	return 1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int x, y, nv;
    Ponto p[4], estudante;
    for(int i = 0; i < 5; i++){
        cin >> x >> y;
        if(i<4){
            p[i].x = x;
            p[i].y = y;
        }
        if(i == 4){
            estudante.x = x;
            estudante.y = y;
        } 
    }
    
    int col1 = SentidoPercurso(p[0],p[1],p[2]);
    int col2 = SentidoPercurso(p[1],p[2],p[3]);
    if(col1 == 0 && col2 == 0){
        cout << " O>" << endl;
        cout << "<| " << endl;
        cout << "/ >" << endl;
    }else{
        nv = ConvexHull(p, 4, ch, nv);
        if(PontoInterior(ch, nv, estudante)){
            cout << "\\O/" << endl;
            cout << " | " << endl;
            cout << "/ \\" << endl;
        }else{
            cout << " O>" << endl;
            cout << "<| " << endl;
            cout << "/ >" << endl;     
        }
    }
    return 0;
}
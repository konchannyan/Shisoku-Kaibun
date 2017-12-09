
#include <stdio.h>

int _ans(char *p)
{
	int i;
	int stack[256] = { 0 };
	for(i = 0; i < 256; i++)
		stack[i] = -1;

	int* sp = stack;
	while(*p){

		if(*p >= '0' && *p <= '9')
			if(*sp == -1)
				*sp = *p - '0';
			else
				*sp = *sp * 10 + *p - '0';

	//	if(*p >= 'a' && *p <= 'd')
//			switch(*p - 'a')
//				case 0:
//					*(sp - 1)

		p++;
	}

}

// a +
// b -
// c *
// d /
// e add

float ans(int *v, int *_o)
{

	int i;
	float x[4];
	int o[3];
	int m_o = -1;

	for(i = 0; i < 4; i++)
		x[i] = v[i];
	for(i = 0; i < 3; i++)
		o[i] = _o[i];

	while(1){

		for(i = 0; i < 3; i++)
			m_o = m_o == -1 && o[i] != -1 ? i : o[m_o] > o[i] ? m_o : i;

		if(m_o == -1 || o[m_o] == -1)
			break;

		int xa = x[m_o];
		int xb = x[m_o + 1];
		switch(o[m_o]){
		case 0:
			xa = xa + xb;
			break;
		case 1:
			xa = xa - xb;
			break;
		case 2:
			xa = xa * xb;
			break;
		case 3:
			if(xb == 0)
				return -1;
			xa = xa / xb;
			break;
		case 4:
			if(xa == 0)
				return -1;
			xa = xa * 10 + xb;
			break;
		}
		
		for(i = m_o; i < 3; i++)
			x[i] = x[i + 1];

		for(i = m_o; i < 2; i++)
			o[i] = o[i + 1];

		x[m_o] = xa;
		o[2] = -1;

	}

	return x[0];

}

int inv(int *v)
{

	if(v[3] == 0) return -1;
	if(v[2] == 0) return -1;
	if(v[1] == 0) return -1;
	int x = v[0] * 1 + v[1] * 10 + v[2] * 100 + v[3] * 1000;
	return x;

}

int main()
{

	int i;
	int i_ans, i_inv;
	int i3, i2, i1, i0, o0, o1, o2;
	int v[4] = { 1, 2, 3, 4};
	int o[3] = { 0, 0, 0 };

	for(i3 = 1; i3 < 10; i3++){
		for(i2 = 0; i2 < 10; i2++){
			for(i1 = 0; i1 < 10; i1++){
				for(i0 = 0; i0 < 10; i0++){
					for(o0 = 0; o0 < 5; o0++){
						for(o1 = 0; o1 < 5; o1++){
							for(o2 = 0; o2 < 5; o2++){
								v[0] = i3;
								v[1] = i2;
								v[2] = i1;
								v[3] = i0;
								o[0] = o0;
								o[1] = o1;
								o[2] = o2;
								i_inv = inv(v);
								i_ans = (int)ans(v, o);
								if(i_inv == i_ans && i_inv >= 0){
									printf("%d", v[0]);
									for(i = 0; i < 3; i++){
										printf("%s", o[i] == 0 ? " + " : o[i] == 1 ? " - " : o[i] == 2 ? " * " : o[i] == 3 ? " / " : "");
										printf("%d", v[i + 1]);
									}
									printf(" = %d\n", i_inv);
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;

}

main(h,v,i)int**v;{h=atoi(v[1]);for(i=h*h;i--;)printf(i%h+i/h<h?i%h?"#":"#\n":" ");}
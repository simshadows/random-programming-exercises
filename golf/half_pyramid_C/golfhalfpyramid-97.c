main(x,v,i,h)char**v;{h=atoi(v[1]);for(i=0;i<h*h;++i)printf(i%h+i/h+1<h?" ":i%h==h-1?"#\n":"#");}
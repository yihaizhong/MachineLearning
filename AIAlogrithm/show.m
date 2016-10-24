function show(cityfile,pathfile,count)
[x,y]=textread(cityfile,'%f %f',count);
path=textread(pathfile,'%d',count);
length=0;
for i = 1:count
    xx(i)=x(path(i)+1);
    yy(i)=y(path(i)+1);    
    if i>1
        length=length+sqrt((xx(i)-xx(i-1))^2+(yy(i)-yy(i-1))^2);
    end
end
xx(count+1)=xx(1);
yy(count+1)=yy(1);
length=length+sqrt((xx(count+1)-xx(count))^2+(yy(count+1)-yy(count))^2)
axis([min(x)-0.5,max(x)+0.5,min(y)-0.5,max(y)+0.5]);
hold on;
plot(xx,yy,'+')
plot(xx,yy)
end
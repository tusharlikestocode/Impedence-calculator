#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
float l,c,r,f,xl,xc,l1,l2,xce,xle;
float z,ze,y,a;
float  c1,c2;
int   series,parallel,ans,option,flag;
char yes,no;
printf("\t                    TT IMPEDANCE CALCULATOR\n");
do{
printf("Enter the resistance(IN OHMS):");
scanf("%f",&r);
printf("Are there multiple inductor?\nIf yes then enter 1 else enter 2:\n");
scanf("%d",&ans);
if(ans==2){
printf("Enter the inductance(IN MILLIHENRY):");
scanf("%f",&l);
}

else if(ans==1){
        printf("Enter the inductance of inductor 1(IN MILLIHENRY):");
        scanf("%f",&l1);
        printf("Enter the inductance of inductor 2(IN MILLIHENRY):");
        scanf("%f",&l2);
        printf("In parallel or in series:\nEnter 1 for series:\nEnter 2 for parallel:\n");
        scanf("%d",&ans);
        if(ans==2){
            l=1/((1/l1)+(1/l2));
            printf("Total inductance=%.2f\n",l);
        }
        else if(ans==1){
            l=l1+l2;
            printf("Total inductance=%.2f\n",l);
        }
}

printf("Are there multiple capacitor?\nIf yes then enter 1 else enter 2:\n");
scanf("%d",&ans);
if(ans==1){
        printf("Enter the capacitance of capacitor 1(IN MICROFARADS):");
        scanf("%f",&c1);
        printf("Enter the capacitance of capacitor 2(IN MICROFARADS):");
        scanf("%f",&c2);
        printf("In parallel or in series:\nEnter 1 for series:\nEnter 2 for parallel:\n");
        scanf("%d",&ans);
        if(ans==1){
            c=1/((1/c1)+(1/c2));
            printf("Total capacitance=%.2f\n",c);
        }
        else if(ans==2){
            c=c1+c2;
            printf("Total capacitance=%.2f\n",c);
        }
}
else if(ans==2){
    printf("Enter the capacitance(IN MICROFARADS):");
    scanf("%f",&c);
    printf("Total capacitance=%.2f\n",c);
}
printf("Enter the frequency(IN HERTZ):");
scanf("%f",&f);
if(c!=0){
xc=1/(2*3.14*f*c*0.000001);
}
else if (l!=0){
    xl=2*3.14*f*l*0.001;
}
printf("REACTANCE(XC)=%.2f\n",xc);
printf("INDUCTIVE REACTANCE(XL)=%.2f\n",xl);
if(xl>xc && f!=0 && f<=2000 ){
    z=sqrt(r*r+(xc-xl)*(xc-xl));
    printf("IMPEDANCE(Z)=%.2f",z);
    xce=1/(2*3.14*(xl-xc)*f*0.000001);
    printf("\nNeeded to add capacitor of %.2f microfarads",xce);


}
else if(xc>xl && f!=0 && f<=2000 ){
    ze=sqrt(r*r+(xl-xc)*(xl-xc));
    printf("IMPEDANCE(Z)=%.2f",ze);
    xle=(2*3.14*(xc-xl)*f*0.001);
    printf("\nNeeded to add inductor of %.2fmH",xle);
}
else if(xc=0 && f!=0 && f<=2000 ){
    y=sqrt(r*r+(xl)*(xl));
    printf("IMPEDANCE(Z)=%.2f",y);
}
else if(xl=0 && f!=0 && f<=2000 ){
    a=sqrt(r*r+(xc)*(xc));
    printf("IMPEDANCE(Z)=%.2f",a);
}
else if(xl=xc)
{
    printf("The circuit is in resonance");
}
    printf("\nPress 1 to continue and or Press 0 to exit\n");
    scanf("%d",&flag);
}while(flag==1);

printf("\t\nTHANK YOU FOR USING TT IMPEDANCE CALCULATOR");
}

























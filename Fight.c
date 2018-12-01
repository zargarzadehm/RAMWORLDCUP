#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
}
int M_Power(void)
{
int x=0,i=0,skill,fitness,form;
    for( int i = 0 ; i < t[n].p[i].Enrollment ; i++ ) {
    	if(t[n].p[i].Condition==1&&t[n].p[i].Player_New_Post=M){
    	skill+=t[n].p[i].skill;
		form+=t[n].p[i].form ;	
		fitness+=t[n].p[i].fitness;}
	}
		fitness=fitness/11;
		skill=skill/11;
		form=form/11;
		x=skill+form+fitness;
		x=x/3,
		return x;
	}
int G_Power(void)
{
int x=0,i=0,skill,fitness,form;
    for( int i = 0 ; i < t[n].p[i].Enrollment ; i++ ) {
    	if(t[n].p[i].Condition==1&&t[n].p[i].Player_New_Post=G){
    	skill+=t[n].p[i].skill;
		form+=t[n].p[i].form ;	
		fitness+=t[n].p[i].fitness;}
	}
		fitness=fitness/11;
		skill=skill/11;
		form=form/11;
		x=skill+form+fitness;
		x=x/3,
		return x;
	}
int D_Power(void)
{
int x=0,i=0,skill,fitness,form;
    for( int i = 0 ; i < t[n].p[i].Enrollment ; i++ ) {
    	if(t[n].p[i].Condition==1&&t[n].p[i].Player_New_Post=D){
    	skill+=t[n].p[i].skill;
		form+=t[n].p[i].form ;	
		fitness+=t[n].p[i].fitness;}
	}
		fitness=fitness/11;
		skill=skill/11;
		form=form/11;
		x=skill+form+fitness;
		x=x/3,
		return x;
	}
int A_Power(int i)
{
int x=0,i=0,skill,fitness,form;
    for( int i = 0 ; i < t[n].p[i].Enrollment ; i++ ) {
    	if(t[n].p[i].Condition==1&&t[n].p[i].Player_New_Post=A){
    	skill+=t[n].p[i].skill;
		form+=t[n].p[i].form ;	
		fitness+=t[n].p[i].fitness;}
	}
		fitness=fitness/11;
		skill=skill/11;
		form=form/11;
		x=skill+form+fitness;
		x=x/3,
		return x;
	}
int Fight(int i, int j)
{
	int a1 = A_Power(i);
	int a2 = A_Power(j);
	int g1 = G_Power(i);
	int g2 = G_Power (j);
	int d1 = D_Power(i);
	int d2 = D_Power (j);
	int m1 = M_Power(i);
	int m2 = M_Power (j);
	int iTotal_Defence=g1+d1+m1;
	int iTotal_Defence=int iTotal_Defence/3;
	int jTotal_Defence=g2+d2+m2	; 
	int jTotal_Defence=int jTotal_Defence/3;
	///////////////////////////////////////////////////////random
	int iGoal=a1-jTotal_Defence;
	int jGoal=a2-iTotal_Defence;
	while (iGoal>10&&jGoal>10){
		iGoal=iGoal/5;
		jGoal=jGoal/5;
	}
	if(iGoal>jGoal){
		//////////////////////////////////////////////////////////////////
	}
	if(iGoal<jGoal){
		///////////////////////////////////////////////////////////
	}
	if(iGoal=jGoal){
		//////////////////////////////////////////////////////////////
	}
	
}

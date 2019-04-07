#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int z[100],z_at[100],z_bt[100],z_pr[100],z_priority[100];
int t_time[100],t_process[100],bsum,p_sum=0,temp=0,p_process,x_sum=0,z_sum=0;
char pr[100];
int m[100],m_at[100],m_bt[100],m_sum=0,priority[100];
int p_f,p_s,count=0;
int p[100],p_at[100],p_bt[100],p_priority[100];
int x[100],x_at[100],x_bt[100],x_priority[100];
int position(int x)
{
int min,pos,i=-1;
do
{i++;
min=z_at[i];
pos=i;
}while(z_bt[i]==0);
for (int i=0;i<x;i++)
	{
	if(z_at[i]<min && z_bt[i] >0)
           { min =z_at[i];
             pos=i;
            } 
               
	}
return(pos);
}
int main()
{

printf("Enter Total number of processes \n");
scanf("%d",&p_process);
printf("process\t\tArriaval time\t\tBurst time\t\tPriority\n");
for(int i=0;i<p_process;i++)
{
printf("P(%d)\t\t",i+1);
while(1)
 {
scanf("%d\t\t%d",&m_at[i],&m_bt[i]);
scanf("\t\t\t\t%d",&priority[i]);
	if(m_at[i] >=0 && m_bt[i] >0 && priority[i]>0)
      {
        m_sum=m_sum + m_bt[i];
	m[i]=i+1; 
        break;
      }
else 
printf("enter valid value again\n");
 }
} 
for(int i=0;i<p_process;i++)
 {
    for(int j=0;j<p_process;j++)
   {
     if(m_at[j]>m_at[j+1] && j<(p_process-1))
     {
      temp=m_at[j];
      m_at[j]=m_at[j+1];
      m_at[j+1]=temp;
      temp=m_bt[j];
      m_bt[j]=m_bt[j+1];
      m_bt[j+1]=temp;
      temp=m[j];
      m[j]=m[j+1];
      m[j+1]=temp;
          
      temp = priority[j];
     priority[j]=priority[j+1];
     priority[j+1]=temp;               

             // end of first queue 
     }
   }
 }
for(int i=0;i<p_process;i++)
 {
    for(int j=0;j<p_process;j++)
   {
     if( j<(p_process-1) && m_at[j]==m_at[j+1] && priority[j]>priority[j+1])
     {
      temp=m_at[j];
      m_at[j]=m_at[j+1];
      m_at[j+1]=temp;
      temp=m_bt[j];
      m_bt[j]=m_bt[j+1];
      m_bt[j+1]=temp;
      temp=m[j];
      m[j]=m[j+1];
      m[j+1]=temp; 
      temp = priority[j];
     priority[j]=priority[j+1];
     priority[j+1]=temp;  
                     // end of first queue
       
     }
   }
 } 
printf ("Enter priority range for First Queue 0 to  \t\t");
while(1)
{
scanf("%d",&p_f);
if (p_f >0)
 {
  break;
 }
else
printf("plz enter valid value\n");

}
printf ("Enter priority range for First Queue %d to  \t\t",p_f+1);
while(1)
{
scanf("%d",&p_s);
if (p_s>p_f && p_s >0)
 {
   break;
  }
else
printf("plz enter valid value\n");

}
int i1=0,i2=0,i3=0;
// assign value to valid queues
for(int i=0;i<p_process;i++)
{
  if(priority[i]<=p_f)
	{
	 p[i1]=m[i];
         p_at[i1]=m_at[i];
         p_bt[i1]=m_bt[i];
        p_sum=p_sum + m_bt[i];
         p_priority[i1]=priority[i];
        printf("priority %d and p_sum is %d\n",p_priority[i1],p_sum);
        i1++;
       
	}
  else if(priority[i] > p_f && priority[i] <= p_s)
	{
	 z[i2]=m[i];
         z_at[i2]=m_at[i];
         z_bt[i2]=m_bt[i];
         z_sum=z_sum + m_bt[i];
         z_priority[i2]=priority[i];
         printf("priority %dand z_sum %d\n",z_priority[i2],z_sum);
         i2++;
	}
   else
	{
          x[i3]=m[i];
         x_at[i3]=m_at[i];
         x_bt[i3]=m_bt[i];
         x_sum=x_sum + m_bt[i];
         x_priority[i3]=priority[i];
         printf("priority %d and x_sum is %d \n",x_priority[i3],x_sum);
         i3++;
	}

 
}


printf("processes\t\tArrival time \t\tBurst time \t\tPriority\n");
for (int i=0;i<p_process;i++)
{
  printf("P(%d)\t\t\t%d\t\t\t%d\t\t\t%d\n",m[i],m_at[i],m_bt[i],priority[i]);
}
printf("\t\t\tfor first queue\nProcesses\t\tArrival time\t\tBurst time \t\tPriority\n");
for (int i=0;p[i]!='\0';i++)
{
  printf("P(%d)\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],p_at[i],p_bt[i],p_priority[i]);
}
printf("\t\t\tfor Second  queue\nProcesses\t\tArrival time\t\tBurst time \t\tPriority\n");
for (int i=0;z[i] !='\0';i++)
{
  printf("P(%d)\t\t\t%d\t\t\t%d\t\t\t%d\n",z[i],z_at[i],z_bt[i],z_priority[i]);
}
printf("\t\t\tfor third queue\nProcesses\t\tArrival time\t\tBurst time \t\tPriority\n");
for (int i=0;x[i]!='\0';i++)
{
	 count++;
  printf("P(%d)\t\t\t%d\t\t\t%d\t\t\t%d\n",x[i],x_at[i],x_bt[i],x_priority[i]);
}


printf("sum of queues %d %d %d  total %d\n",p_sum,z_sum,x_sum,m_sum);

          // main loop start from here
int qu1=0,qu2=0;
int check=-1,temp,quanta;
pr[0]='N';
int t_v=-1;
t_process[0]=-1; 
t_time[0]=0;
int j=0,i=0;
int var,test=0;
bsum=m_sum;
while(bsum>0)
{        
            var=t_time[j];
    while((t_time[j]-var)<10)
             {
            if(p_sum<=0)
                {
                  break; 
                }
	    if(check==i)
                {quanta =temp;}
             else{quanta = 4;}
            if(p_at[i]<=t_time[j])
                {
                 if(p_bt[i] >=quanta && (10-(t_time[j]-var)) >=quanta)
                       { 
                         pr[j+1]='P';
			 if(i>t_v)
			 {
                         test=test+p_bt[i];
			   t_v++;	 
			 }	 
                         t_time[j+1]=t_time[j] +quanta;
                         t_process[j+1]=p[i];
                         bsum= bsum -quanta;
                         p_sum=p_sum-quanta;
                         p_bt[i]=p_bt[i]-quanta;
                         test=test-quanta;
                         temp=4;  
                        }
               else if(p_bt[i] >=quanta)
                        { 
                         pr[j+1]='P';
                        if(i>t_v)
			 {
                         test=test+p_bt[i];
			   t_v++;	 
			 }
                         t_time[j+1]=t_time[j] + (10-(t_time[j]-var)) ;
                         t_process[j+1]=p[i];
                         bsum= bsum -(10-(t_time[j]-var));
                         p_sum=p_sum-(10-(t_time[j]-var));
                         p_bt[i]=p_bt[i]-(10-(t_time[j]-var));
                         test=test-(10-(t_time[j]-var));
                         temp=quanta-(10-(t_time[j]-var));
                         check=i;
                          i--;
                         }
                 else if( p_bt[i] <4 && p_bt[i]>0 && (10-(t_time[j]-var)) >=p_bt[i])
                        { 
                         pr[j+1]='P';
			 if(i>t_v)
			 {
                         test=test+p_bt[i];
			   t_v++;	 
			 }
                         t_time[j+1]=t_time[j] + p_bt[i];
                         t_process[j+1]=p[i];
                         bsum= bsum -p_bt[i];
                         p_sum=p_sum - p_bt[i];
			 test=test-p_bt[i];
                         p_bt[i]=p_bt[i]-p_bt[i];
			 temp=4;
                        }
                 else if(p_bt[i] <4 && p_bt[i]>0 && (10-(t_time[j]-var)) <p_bt[i])
                        {temp=4;
                         pr[j+1]='P';
                         if(i>t_v)
			 {
                         test=test+p_bt[i];
			   t_v++;	 
			 }
                         t_process[j+1]=p[i];
                         t_time[j+1]=t_time[j] + (10-(t_time[j]-var));
                         bsum= bsum -(10-(t_time[j]-var));
                         p_sum=p_sum - (10-(t_time[j]-var));
                         p_bt[i]=p_bt[i]-(10-(t_time[j]-var));
                         test=test-(10-(t_time[j]-var));
                          
                        }
                  else 
                        { temp=4;
                         j--;  
                        }
                  
                }
            else 
               { if(j==0 )
                  {
                   if(j==0 )
                  {  
                      if((p_at[i]-t_time[j]) <= (10-(t_time[j]-var)  )){                             
                  	 t_time[j+1]=p_at[i]; 
			}
                      else{
			t_time[j+1]=t_time[j]+(10-(t_time[j]-var)  );
                 t_process[j+1]=-1;
                 pr[j+1]='N'; 
                i=-1;  
                 }
                else 
                     {  if(test==0)
		        { 
			      if(j==0 )
                  {  
                      if((p_at[i]-t_time[j]) <= (10-(t_time[j]-var)  )){                             
                  	 t_time[j+1]=p_at[i]; 
			}
                      else{
			t_time[j+1]=t_time[j]+(10-(t_time[j]-var)  ); 
                               t_process[j+1]=-1;
                                pr[j+1]='N'; 
                               i=-1;  
		        } 
                        else{    j--;
                            i=-1;}
                           
                     }  
                       
               }
              
              i++;
                 if(p[i]=='\0')
                  {
                   i=0; 
                 }
          j=j+1;
    }
i=qu1;
 i=0;     
        
     // Second Queue
                                                     
            var=t_time[j];
    while((t_time[j]-var)<10)
{ 
	    pos=position(count);
		if(z_sum==0)
	{
	break;
	} 
  else if(z_at[pos]<=t_time[j]) 
	{
	  	if(z_at[i]<=t_time[j] && z_bt[i]>0)          
	    	    { 		
                 		 int x,timegp;
                 		   x =position(i);
		 		 timegp=z_at[x]-z_at[i];
		 	    if(timegp==0 || z_bt[i]<=timegp)
				{
					if(z_bt[i] <= (10-(t_time[j]-var)) && z_bt[i]>0)
                   			    { 
                    			     pr[j+1]='Z';
                    			     t_time[j+1]=t_time[j] + z_bt[i];
                    			     t_process[j+1]=z[i];
                    			     bsum= bsum -z_bt[i];
				         	z_sum=z_sum-z_bt[i];
                   			      z_bt[i]=0;
                          
                     		            }
				else           
					{
					 
                		         pr[j+1]='Z';
             			            t_time[j+1]=t_time[j] + (10-(t_time[j]-var));
                		         t_process[j+1]=z[i];
                		         bsum= bsum -(10-(t_time[j]-var));
                		         z_sum=z_sum-(10-(t_time[j]-var));
                		         z_bt[i]=z_bt[i]-(10-(t_time[j]-var));
                		      
                          
				    }
				
		  	      }
			else
			{
			  if(timegp <= (10-(t_time[j]-var)))
    				{
				                pr[j+1]='Z';
                    			        t_time[j+1]=t_time[j] + timegp;
                    			        t_process[j+1]=z[i];
                    			        bsum= bsum -timegp;
				         	z_sum=z_sum-timegp;
                   			        z_bt[i]=z_bt[i]-timegp;
                                                      i=-1;
				}
			  else 
				{ 
				               pr[j+1]='Z';
                    			       t_time[j+1]=t_time[j] + (10-(t_time[j]-var));
                    			       t_process[j+1]=z[i];
                    			       bsum= bsum -(10-(t_time[j]-var));
				               z_sum=z_sum-(10-(t_time[j]-var));
                   			       z_bt[i]=z_bt[i]-(10-(t_time[j]-var));
				}
			}
	              }
	  
           else
		{
		j--;
		}
	}
      else 
	{
	  if((z_at[pos]-t_time[j])<=(10-(t_time[j]-var)))
		{
		  t_time[j+1]=z_at[pos];    
		}
	else{
		t_time[j+1]=t_time[j]+(10-(t_time[j]-var));   // change here
        	}
                 t_process[j+1]=-1;
                 pr[j+1]='N';  
                i=-1; 
	}
    
     i++;
                 if(z[i]=='\0')
                  {
                   i=0; 
                 }
          j=j+1;
  
}
qu2=i;
i=0;    
            var=t_time[j];
          
while((t_time[j]-var)<10)
{
	if(x_sum==0)
	{
	break;
	}
	else if(x_at[i]<=t_time[j]) 
	{
	  if(x_bt[i] <= (10-(t_time[j]-var)) && x_bt[i]>0)
                       { 
                         pr[j+1]='X';
                         t_time[j+1]=t_time[j] + x_bt[i];
                         t_process[j+1]=x[i];
                         bsum= bsum -x_bt[i];
                         x_sum=x_sum-x_bt[i];
                         x_bt[i]=0;
                        
                        }
	else if(x_bt[i]>(10-(t_time[j]-var)) && x_bt[i]>0)
		{
		 
                         pr[j+1]='X';
                         t_time[j+1]=t_time[j] + (10-(t_time[j]-var));
                         t_process[j+1]=x[i];
                         bsum= bsum -(10-(t_time[j]-var));
                         x_sum=x_sum-(10-(t_time[j]-var));
                         x_bt[i]=x_bt[i]-(10-(t_time[j]-var));
                         
                          
		}
	else 
		{
		 j--;
		}
	}
      else 
	{
	  if((x_at[i]-t_time[j])<=(10-(t_time[j]-var)))
		{
		  t_time[j+1]=x_at[i];   
		}
	else{
		t_time[j+1]=t_time[j]+(10-(t_time[j]-var));  
        	} 
                 t_process[j+1]=-1;
                 pr[j+1]='N'; 
                i=-1; 
	}
    
     i++;
                 if(x[i]=='\0')
                  {
                   i=0; 
                 }
          j=j+1;
 
}


}
printf("\n\n*************************Ghantt chart of Processes*********************************\n\n");
for(int k=0;k<j;k++)
{
   		printf("========");

}
printf("\n||");
for(int k=0;k<=j;k++)
{
  if(k<j){  if (t_process[k+1]!=-1)
   		printf(" p(%d) ||",t_process[k+1]);
            else {printf(" NONE ||");}
	}   

}
printf("\n");
for(int k=0;k<j;k++)
{
   		printf("========");

}
printf("\n0");
for(int k=0;k<=j;k++)
{
  if(k<j){	
  printf("\t%d",t_time[k+1]);
         }

}
printf("\n"); 
for(int k=0;k<j;k++)
{
   		printf("========");

}
printf("\n0");
for(int k=0;k<=j;k++)
{
  if(k<j){	
  printf("\t%d",t_time[k+1]);
         }

}
printf("\n");
float aw,ab,awt=0,att=0;
int npb[100],npa[100];
int prt[100],start[100],end[100],f=0;
for(int i=0 ; t_process[i]!='\0';i++)
{
  if(t_process[i]!=-1)
	{
	 prt[f]=t_process[i];
         start[f]=t_time[i-1];
	 for(int l =j;l>=0;l--)
		{
		 if(t_process[i]==t_process[l])
			{
			end[f]=t_time[l];
                        break;
			}
		}
            f++;
	}
}
for(int i=0;i<p_process;i++)
{ for(int j=0;j<p_process;j++)
	{
	if(prt[i]==m[j])
		{
		 npa[i]=m_at[j];
                 npb[i]=m_bt[j];
                 break;
		}
	}
 
}
printf("------------------------------------------------------------------------------\n");
printf("\t\t\tPROCESS TABLE\n");
printf("------------------------------------------------------------------------------\n");
printf("PROCESS\t\tTURN AROUND TIME \t WAITING TIME\tCOMPLITION TIME\n"); 
for(int i=0; i<f;i++)
{
printf("P(%d)\t\t %d \t\t\t\t%d\t\t%d\n",prt[i],end[i]-npa[i],(end[i]-npa[i]-npb[i]),end[i]);
  awt=awt+(end[i]-npa[i]-npb[i]);
  att=att+end[i]-npa[i];
} 
aw=awt/f;
ab=att/f;
printf("\t\t-------------\t\t-------------\n");
printf("AVARAGE\t\t%0.3f\t\t\t\t%0.3f\n",ab,aw); 
printf("\t\t--------------\t\t-------------\n");
}

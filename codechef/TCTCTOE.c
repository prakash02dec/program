#include <stdio.h>

int main(void) {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        register int i,j;
        int move=0 ,xwin=0,owin=0,x=0,o=0; 
        char board[3][3];
        for(i=0;i<3;i++)
        {
            scanf("%s",&board[i][0]);
        }
        if(board[0][0]==board[1][1] && board[2][2]==board[1][1])
        {
            if(board[0][0]=='X')
            xwin++;
            else if(board[0][0]=='O')
            owin++;
        }
        if(board[0][2]==board[1][1] && board[2][0]==board[1][1])
        {
            if(board[0][2]=='X')
            xwin++;
            else if(board[0][2]=='O')
            owin++;
            
        }
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(j==0)
            {
                if(board[i][0]==board[i][1] && board[i][2]==board[i][1]  )
                {
                    if(board[i][0]=='X')
                    xwin++;
                    else if(board[i][0]=='O')
                    owin++;
                
                }
                if(board[0][i]==board[2][i] && board[2][i]==board[1][i] )
                {
                    if(board[0][i]=='X')
                    xwin++;
                    else if(board[0][i]=='O')
                    owin++;
                
                }
            }

            if(board[i][j]=='X')
            x++;
            else if(board[i][j]=='O')
            o++;
            else if(board[i][j]=='_')
            move++;            
        }
        // for(i=0;i<3;i++)
        // {
        //     for(j=0;j<3;j++)
        //     printf("%c ",board[i][j]);
        //     printf("\n");
        // }
        // printf("\n%d %d %d %d %d\n",x,o,move,xwin,owin);
        
        if((o>x) || (x-o>1))
        printf("\n3");
        else if(move>0 && xwin+owin==0)
        printf("\n2");
        else if((x>o && xwin==1 && owin==0)||(x==o && xwin==0 && owin==1) || (move==0 && owin+xwin==0) || (move==0 && xwin==2))
        printf("\n1");
        else
        printf("\n3");
        
    }
	return 0;
}


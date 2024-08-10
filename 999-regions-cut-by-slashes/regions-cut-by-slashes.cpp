class disjointset{
public:
    vector<int>par,size;
    int count=1;
    disjointset (int n)
    {
        par.resize(n);
        size.resize(n);

        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }        
    }

    int findpar(int node)
    {
        if(node==par[node])return node;

        return par[node]=findpar(par[node]);
    }

    void ubs(int u,int v)
    {
        int p1=findpar(u);
        int p2=findpar(v);

        if(p1==p2)
        {
            count++;
            return;
        }

        if(size[p1]<size[p2])
        {
            par[p1]=p2;
            size[p2]+=size[p1];
        }
        else
        {
            par[p2]=p1;
            size[p1]+=size[p2];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int val=(n+1)*(n+1)+1;

        disjointset ds(val);

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0 || i==n || j==n)
                {
                    int cellno=(i*(n+1))+j;
                    if(cellno!=0)
                    {
                        ds.ubs(0,cellno);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int dot1= i * (n+1) + (j+1);
                    int dot2= (i+1) * (n+1) + j;
                    ds.ubs(dot1,dot2);
                }
                else if(grid[i][j]=='\\')
                {
                    int dot1= i * (n+1) + (j);
                    int dot2= (i+1) * (n+1) + (j+1);
                    ds.ubs(dot1,dot2);
                }
            }
        }
        return ds.count;
    }
};
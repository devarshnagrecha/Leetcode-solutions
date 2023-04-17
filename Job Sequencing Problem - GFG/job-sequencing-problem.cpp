//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(Job a, Job b)
    {
        if (a.profit==b.profit)
            return a.dead<b.dead;
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int count = 0, profit = 0, maxDeadline = -1;
        sort (arr, arr + n, cmp);
        
        for (int i=0; i<n; i++)
        {
            maxDeadline = max (maxDeadline, arr[i].dead);
        }
        
        vector<bool>vis(maxDeadline+1, false);
        
        for (int j=0; j<n; j++)
        {
            if (!vis[arr[j].dead])
            {
                vis[arr[j].dead]= true;
                count++;
                profit += arr[j].profit;
            }
            
            else
            {
                for (int i=arr[j].dead; i>0; i--)
                {
                    if (!vis[i])
                    {
                        vis[i]=true;
                        count++;
                        profit += arr[j].profit;
                        break;
                    }
                }
            }
        }
        
        return {count,profit};
        // your code here
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
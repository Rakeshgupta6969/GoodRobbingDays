class Solution {
     
     private:
     bool leftcheck(vector<int> &security,int time,int index){
         bool check = true;
       for(int i = index - time; i<index; i++){
            if(security[i]<security[i+1]){

                check = false;
                break;
            }
       }
        return check;
     }


   bool rightcheck(vector<int> &security,int time,int index){
     
     bool check  = true;

     for(int i  = index; i<index+time; i++){
      
         if(security[i]>security[i+1]){
            check = false;
            break;
         }


     }

    return check;

   }




public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        

          // using the brute force solution

    //       int n = security.size();



    //       vector<int> ans;

    //       for(int i  = time; i<n-time; i++){
          
    //        bool check1 = leftcheck(security,time,i);
    //        bool check2 = rightcheck(security,time,i);

    //        if(check1 && check2){
    //         ans.push_back(i);
    //        }



    //       }

     // using the optimal solution with the help of the prefixcount and suffixcount.



     int n  = security.size(); 

     vector<int> ans;


      vector<int> decL(n,0);  // decreasing from left
      vector<int>decR(n,0); // decreasing from right.

      if(time == 0){
        
        for(int  i = 0; i<n; i++){
            ans.push_back(i);
        }

       return ans;
      }


        

      // decreasing streak from left;

      for(int i = 1; i<n; i++){
         
          if(security[i]<=security[i-1]){

          decL[i] = decL[i-1]+1;

          }

      }

      // decreasing streak form right.

      for(int i = n-2; i>=0; i--){

       if(security[i+1]>=security[i]){
        decR[i] = decR[i+1] + 1;

       }

      }
     


       // now updating the ans. that means find the valid days.

       for(int i = time; i<n-time; i++){
        if(decL[i]>=time && decR[i]>=time){
            ans.push_back(i);
        }
       }

         return ans;
    }
};
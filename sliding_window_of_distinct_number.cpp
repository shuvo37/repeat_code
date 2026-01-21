 ll atMostK(vector<int> &arr , int lim_of_distinct_value)
    {

          int n = arr.size();

          int j = 0;

          vector<int> cnt(mx , 0);

          ll count_subarray = 0;

          int distinct = 0;

          for(int i = 0; i < n; i++)
          {

               while( j < n && lim_of_distinct_value >= distinct)
               {

                   if( !cnt[arr[j]] && !cnt[arr[j]] + distinct <= lim_of_distinct_value)
                   {

                       distinct++;

                       cnt[arr[j]]++;
                   }
                   else if(!cnt[arr[j]] + distinct <= lim_of_distinct_value)
                   {
                      cnt[arr[j]]++;

                   }

                   if(!cnt[arr[j]] + distinct > lim_of_distinct_value)
                   {

                         break;

                   }

                    j++;



               }



                   count_subarray +=(j - i);

                   ///cout << " i : "<< i << " "<<  (j - i) << " j : "<< j << " distinct : " << distinct << endl;




               cnt[arr[i]]--;

               if(cnt[arr[i]] == 0)
               {

                   distinct--;
               }



          }


          return count_subarray;


    }

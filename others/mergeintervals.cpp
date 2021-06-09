    //code for merge intervals ...
    
    int idx=0;
		for(int i=1;i<interval.size();i++)
		{
			if(interval[i].first<=interval[idx].second)
			{

			 interval[idx].second =max(interval[idx].second,interval[i].second);

			}
			else
			{
				idx++;
				interval[idx]=interval[i];


			}
		}
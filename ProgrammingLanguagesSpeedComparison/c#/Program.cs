using System;

namespace c_;

class Program{
	static void Main(string[] args){
		const int repreats = 5;
		const long t1 = 10000000000;
		const long t2 = 1000000000;
		int[] times = new int[repreats];

		for(int c = 0; c < repreats; c++){
			times[c] = Environment.TickCount;

			/*Counting test
			int result = 0;
			for(long i = 0; i < t1; i++){
				result += (int)i;
			}*/

			/*Printing test
			for(long i = 0; i < t2; i++){
				Console.Write('-');
			}*/

			//If test
			int result = 0;
			for(long i = 0; i < t1; i++){
				if(i % 2 == 0){
					result++;
				}
				if(i % 3 == 0){
					result--;
				}
			}

			times[c] = Environment.TickCount - times[c];
		}
		int t_avg = 0;
		for(int i = 0; i <  repreats; i++){
			t_avg += times[i];
		}
		Console.WriteLine((t_avg / repreats));
	}
}

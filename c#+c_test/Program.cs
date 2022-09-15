using System;
using System.Runtime.InteropServices;

namespace c__c_test;

class Program{
  [DllImport("dlls/print.dll", EntryPoint = "print")]
  public extern static void print(string str);

  static void Main(string[] args){
    print("Hello World!\n");
  }
}

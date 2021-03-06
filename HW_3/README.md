# HW 3

## Work with testing tool of UE, plugins and UMG

In this homework was created a new plugin `CalculatorENBF` which creates UMG widget with a calculator. In the plugin exist h and cpp files `Calculator.h/cpp` where implemented logic of computation of math expression with +,-,*,/ operations. Was created a function `Compute` with *UFUNCTION(BlueprintCallable, meta = (Category = "CalculatorEBNF"))* to call this function from Blueprint Scripts. This class implements only computing and there is no any validation check of expressions.

To testing Compute method was created a Unit Test Class `FCalculatorEBNF_Compute` which can be run from Test Automation UEEditor (PrettyName = CalculatorEBNF.Compute) and from .bat file (run_tests.bat), where you have to input three arguments (Project Name = UE_Learning\HW_2\HW_2.uproject; PrettyName = CalculatorEBNF.Compute; Log file nmae = output.txt), results are stored in Saved\Logs\Log file name.txt.

To demonstrate work of class was created UMG widget `CalculatorWidget.uasset`. To check this widget move to TestMap.uasset in Contents of HW_2 project, not of plugin, and run project. This widget creates a simple grid of buttons, button "Reset", and two text component. When you click on button you append a symbol to current expression that you can see on screen, when you click button `=`, you can see the result of expression, if you want to type a new expression, you should click on button `Reset`.

***!NOTE***: To run from code you have to firstly run UE5 project and then "Tools > Refresh Visual Studio Project".

## Demonstration of work of Test Automation from UEEditor
![2022-06-21 16-20-13](https://user-images.githubusercontent.com/34779566/174809739-852bd6dc-1611-405c-ab35-82c54339e1f5.gif)

## Demonstration of work of Test Automation from run_tests.bat file
![2022-06-19 04-10-31](https://user-images.githubusercontent.com/34779566/174461863-11a3b056-785f-4ced-80fb-fc8d79c6473e.gif)

## Demonstration of work of UMG Widget
![2022-06-21 16-27-39](https://user-images.githubusercontent.com/34779566/174811706-13fd4796-9277-40ef-8a1f-3ced62df5763.gif)

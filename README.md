# The Drink Shop
This is a Drink Shop machine for both the clerk and the orders of customers.

## Introduction to this project
The shop currently has only one clerk whose name is Tim and was responsible for the following jobs:
* Start the machine daily before work
* Close the machine daily after work
Each time Tim clocks in and clocks out the time will be printed on the time card of the clerk.

After the machine is on, customers can make orders through the machine.
Customers could choose either one of the options below..
* Check the drinks menu of the shop
* Check the shops information
* Make orders

## :wrench: Functions & :walking: STEPs

### :triangular_flag_on_post: the Clerk Open the Drink Shop & Instructions to the Machine is displayed
The clerk `Tim` should first type his name in order to turn on the machine.
<img src="demo_imgs\StartandInstruction.png" width=50%/>

### :clipboard: Shop Menu (Command: MENU)
<img src="demo_imgs\Menu.png" width=50%/>

### :tropical_drink: Shops Information (Command: SHOPINFO)
<img src="demo_imgs\Shopinfo.png" width=50%/>

### :pencil: Make Orders
<img src="demo_imgs\order.png" width=50%/>

### :white_check_mark: Confirm Orders
<img src="demo_imgs\confirmorder.png" width=50%/>

### :scroll: Need a Receipt? (Command: YES or NO)
<img src="demo_imgs\askReceipt.png" width=50%/>

### :game_die: Discount Challenge Game (Command: YES or No)
<img src="demo_imgs\discountChallenge.png" width=50%/>

### :slot_machine: Pick a Number against the Machine (Command: 1/2/3/4/5/6)
<img src="demo_imgs\ingame.png" width=50%/>

### 🖨️ Print Out the Receipt(E-Invoice) on the Machine
<img src="demo_imgs\invoice.png" width=50%/>

### :heavy_check_mark: Get Point(s) & Print Out the Loyalt Card
<img src="demo_imgs\loyaltcard.png" width=50%/>

### :money_with_wings: Pay your Orders
<img src="demo_imgs\pay.png" width=50%/>

### :closed_lock_with_key: Shop Closed (Command: CLOSE)
To close the shop, the clerk has to type his name which is `Tim`.
<img src="demo_imgs\closeshop.png" width=50%/>


## :warning: Issues & :key: Solutions
You might encounter Warning Message "source file not compiled", recommended solution is..
Go to the path `C:\Dev-Cpp\libexec\gcc\mingw32\3.4.2` and delete the `collect2.exe` file.

## Reference
issue solution: [Stack Overflow-Source file not compiled Dev C++](https://stackoverflow.com/questions/14514682/source-file-not-compiled-dev-c)
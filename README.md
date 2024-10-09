CS 2401 – Fall 2023  
# Labs 9 & 10 – Inheritance and Virtual Functions  
UML diagram and Product child class implementations Due: 11:59 PM Friday, November 3rd  
Order class and main program Due: 11:59 PM Friday, November 10th  

***   
**You may not use any libraries or constructs that we have not talked about in class for this assignment.**  
**This is a group assignment; you must work in teams of 3 – 4 students from your assigned lab section.** After you have formed your team, have one person accept the assignment on GitHub and create your team. Then, everyone else can accept the assignment and join the team. 

***  

Congratulations, you are opening your own business! Luckily, you are all great programmers, so you are working together to design the order management system for your business. You will each be offering at least 4 different products to your customers, however, the attributes that would be used to describe those things can vary greatly. You would not use the same variables (or attributes) to describe a sweater that you would use to describe a pair of pants, let alone a soccer ball or the fancy new soaps you make.  

Since you are each offering different products, think of your products as a “department” in the overall business (the products you offer should be related to each other in some way). Since you are working together, the departments also should be somehow related to each other, but everyone must have unique products. For this project you are to create a group of classes that describe the products that your business will offer. Since they have the common feature of being sold by you, there will be a parent class called something like “Product” (which everyone in the group can share) and then a minimum of 4 other classes per group member which are children of this class. Each child class should have input and output functions, and a function or attribute associated with the cost of the item. These functions will need to be virtual in the parent.   

You are also to construct, for 10% of your grade, a UML class diagram which describes your classes, but does not need to describe the entire application. This diagram is to be constructed using Star UML and should be in the form of a .mdj file, that is included with your project submission. (Star UML is available for free at https://staruml.io/download). You can decide if you want every member of the team to make their own UML diagram or have everyone add their child classes to the same diagram (if you go with one diagram, make sure that it is clear which items belong to each team member).  

***  

Develop the Product class first in the main branch of the repository. Then, each group member should create their own branch for the development of their specific items. To do this, each group member should: 

1. Create a clone of the repository on your machine.  
2. Move yourself into that folder (you should see the product.h and product.cc files).  
3. Create a branch using the command:
   
   **git checkout –b <your_branch_name>**
   
   Replace <your_branch_name> with whatever you want to call your branch. It should be something that describes what the branch is for. I would suggest something that includes your department name. For example, clothing-department-products.  
   This command will create a new branch AND switch you onto that branch. It is equivalent to running:
   
   **git branch <your_branch_name>**  
   **git checkout <your_branch_name>**

4. You should now do all your product class development here. You can use this branch in exactly the same way you are used to using the main branch (pull, add, commit, push). The first time you push your code, it will likely ask you to set the origin, just run the command suggested.  
5. Once you are done developing your classes, you will need to merge your code back into the main branch. DO NOT MERGE UNTIL YOUR CLASSES ARE COMPLETE. To do this:
   * Make sure you have pushed all the code to your individual branch.
   * Checkout the main branch:
     
     **git checkout main**  
     
   * Make sure that you have the most up-to-date version of the main branch (because someone else may have merged their code already):
     
     **git pull**  
     
   * Merge your code into the main branch:  
     
     **git merge <your_branch_name>**  

     Replace <your_branch_name> with the real name of your feature branch.  

   * Push the merged code back to GitHub:  

     **git push**

***    
# Main application directions 

Before you begin writing the main application, you need to develop a class called Order that will store the name of the person ordering, the total cost of the order, and a list of items included in the order. The list of items can be stored using an STL list of Product pointers. You need to include a function that can output all the Order’s information in a format that is pleasing and easy for the user to read. You also need an input function so that users can add items to the Product list. 

 

The main application for this project must maintain an STL list of Orders. The user should be presented with a menu with the following options: 

1. Add a product to the current order. This option should:  
   * Take the user to a sub menu that asks which department they want to pick an item from.  
   * Ask the user which item they want to add from the department they just chose.  
   * Dynamically allocate the item and call the input function so the user can pick their options.  
   * Use the push_back member function to add this item to the Order’s item list.  
2. Add the current order to the list.  
   * This option should use the push_back member function to add the order to the main list.  
3. View a list of all orders.  
   * You can call your order class’s output function which should use an iterator to walk through the list of items and call each one’s output function. Since each item in the list is of type Product*, the syntax for calling the output function is:
     
     (*it) -> output(cout);
     
5. Remove an order that has been completed.
   * Declare an iterator for the list and walk through it until you find the one you want to remove.
   * Pass this iterator to the erase function to remove the item.  
6. Exit the program (which should save all data to the backup file). 

 ***  

Finally, you need to write a backup file system so that a user does not have to reenter all the products that have been ordered every time they start the program. This backup file is to be invisible to the user (call it orders.txt). The program simply looks for the file, and if it is not found it is assumed that this is the first use of the program, but if it is found the product orders are put into the list the same way as they were when entered from the keyboard. Following the loading of the list from a file the user is taken to the main menu. When the program ends, you should save the information for all orders to the orders.txt output file.  

**NOTE:** Because each item in the order has very different attributes, you will need to come up with a system for how to “mark” items in the data file with their type so that you can read in the type first and then dynamically allocate the correct type of item before you read in the attributes. 

You are **NOT** writing a container but are instead using the STL list class. (Available if you #include \<list\>.) For this project you will just need the push_back and erase member functions and the iterator, which is bidirectional, but which you will only be using in a forward direction. 

I am giving you no code for this project – you are to write it all yourself, and variety and creativity of the child classes is a factor in determining your grade.   

**Your final GitHub repository should include** your UML diagram(s), product.h, product.cc, order.h, order.cc, main.cc and a branch for each group member that includes their child classes which has been merged back into the main branch (all item header and .cc files will need to be in the main branch as well). 

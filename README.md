Assignment 3 
implemnting a queue data structure using a linked list  writing a recusive linear seach function and modifying the code so it can sort a list
those were the respective goals of this assignment to run the program you just download the files
put them into some C++ complier and have it run or use the bash then file name in order to run it Command prompt
For the first one I had Implement the queue using only a singly linked list Implementing the needed functions
First a push function to just insert a value at the rear pop function to remove one from the front
a front function to retunr a value to the front of it and a size function telling how many item their are
with finally a empty function to just make sure its not empty or if it is

For the move_to_rear() function I used only the front() pop() and push() function 
first pushing a set of numbers 1 to 10 throught my move to rear function 
<img width="506" height="108" alt="image" src="https://github.com/user-attachments/assets/8a2b2b8d-c657-4735-8e11-fb72263f76f9" />
printing the new list ordered with one being at the front
showing that the push function is working clearly 
<img width="596" height="672" alt="image" src="https://github.com/user-attachments/assets/cca10ae9-47fe-451e-b27a-09e922bbd232" />
<img width="697" height="611" alt="image" src="https://github.com/user-attachments/assets/9e228000-a480-4f9a-a092-e259f75e2454" />

For the next part of the recusive linear search function with the recursive step that finds the last occurence of a target in a vector Firstly I started at the end of the vector instead of the front
then went backwards to find the indexes earliest appernce and comparing that to its last appearnce 
to find out that the last time it appeared was in index 5 as it correctly prints out
<img width="430" height="138" alt="image" src="https://github.com/user-attachments/assets/f9adf55b-9bd6-4e27-b032-be8c57f1d40c" />
<img width="671" height="92" alt="image" src="https://github.com/user-attachments/assets/81b75b42-44ea-4b99-a06c-08bbd466e8c3" />
<img width="722" height="288" alt="image" src="https://github.com/user-attachments/assets/684b2fcd-d777-493a-8d84-1b63827d7c95" />

for the final part of the the assignment the modifying of the source code for the insertion sort so that it can work for integers I modified the original insertion sort by changing how it indexed and instead having to go through the list using next pointers
and then taking taht value and putting each of those values into their correct position within a seperate sorted list As the screenshot shows the original was 5 2 8 1 3 then it became 1 2 3 5 8
Meaning that the new algorithim is working perfectly.
<img width="387" height="97" alt="image" src="https://github.com/user-attachments/assets/a2fabf30-e12b-4412-9f8e-59e27b263e22" />
<img width="703" height="862" alt="image" src="https://github.com/user-attachments/assets/855f8ee2-b2f4-46f3-8c03-8f39ce590f49" />
<img width="542" height="150" alt="image" src="https://github.com/user-attachments/assets/caafa794-1968-4649-8f3a-a8af460ce588" />


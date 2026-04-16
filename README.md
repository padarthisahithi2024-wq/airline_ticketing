   📌 Project Title Airline Ticketing System 

     Flight Connection Graph with CRUD Operations

👥 Team Members 

Student 1: Padarthi Sahithi

Student 2: Syed Sameer Ahamed


📖 Problem Statement

 Airline networks connect multiple airports through flights. Managing these flight connections efficiently is important for storing and updating route information. This project develops a menu-driven Airline Ticketing System in C. Airports are represented as vertices, and flights are represented as edges with ticket prices as weights using a graph data structure. The system allows users to perform CRUD operations such as adding, displaying, updating, searching, and deleting flight records. Dynamic memory allocation and file storage are used so that flight data remains stored even after the program exits.

🧠 Data Structure Used 

The project uses a Graph (Adjacency List Representation) to represent the airline network. Vertices (Nodes): Airports Edges: Flight connections between airports Weights: Ticket prices The graph is implemented using struct, linked lists, and dynamic memory allocation (malloc, free). Example: Chennai → Delhi (5000) → Mumbai (6500) Delhi → Mumbai (3000) Mumbai → No outgoing flights
In this example, Chennai, Delhi, and Mumbai are vertices, while the arrows represent flight connections with ticket prices as weights.

⚙️ Algorithm Explanation

Add Flight (Create) Enter source airport index. Enter destination airport index. Enter ticket price. Create a new edge using dynamic memory (malloc). Insert the edge into the adjacency list.
Display Flights (Read) Traverse the adjacency list of each airport. Display all connected flights and their ticket prices.
Update Flight Price (Update) Search the adjacency list of the source airport. Locate the destination airport. Update the ticket price.
Delete Flight (Delete) Traverse the adjacency list. Find the destination node. Remove it and release memory using free().
Search Flight Traverse the adjacency list of the source airport. If destination is found, display the ticket price.
File Storage When the program exits, all flight data is saved in flights.txt. When the program starts again, the data is loaded from the file. This ensures permanent storage of flight data.


💻 Compilation Instructions Compile the Program gcc main.c -o airline
Run the Program

For Linux/Mac:
./airline
For Windows:
Airline.exe


🖥️ Sample Output

<img width="881" height="720" alt="Screenshot 2026-04-04 164411" src="https://github.com/user-attachments/assets/9cc8beed-0242-47df-ad53-8c3637ef016a" />


<img width="740" height="390" alt="Screenshot 2026-04-04 164422" src="https://github.com/user-attachments/assets/f12f708f-859d-417b-bfe0-2adaf48ced6a" />


<img width="657" height="291" alt="Screenshot 2026-04-04 164440" src="https://github.com/user-attachments/assets/2592c562-ca4e-4a8f-aa29-96581712f155" />


<img width="897" height="671" alt="Screenshot 2026-04-04 164450" src="https://github.com/user-attachments/assets/65835106-fd66-4591-983d-33d8e27e9fda" />


<img width="987" height="671" alt="Screenshot 2026-04-04 164500" src="https://github.com/user-attachments/assets/0e0336f1-cdb7-4bd1-81dd-df2ec61e66e2" />


<img width="860" height="266" alt="Screenshot 2026-04-04 164510" src="https://github.com/user-attachments/assets/878bccbf-9cb7-4053-8c35-8e4a4293e451" />


📌 Conclusion

    This project demonstrates the practical use of graph data structures in C programming to model airline flight connections. The system successfully performs CRUD operations and stores flight data permanently using file handling. This project shows how data structures can be applied to solve real-world problems like airline network management.

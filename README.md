# airline_ticketing


📌 Project Title
Airline Ticketing System – Flight Connection Graph with CRUD Operations

👥 Team Members
Student 1: Padarthi Sahithi
Student 2: Syed Sameer Ahamed

📖 Problem Statement
Airline networks connect multiple airports through flights.
Managing these flight connections efficiently is important for storing and updating route information.
This project develops a menu-driven Airline Ticketing System in C.
Airports are represented as vertices, and flights are represented as edges with ticket prices as weights using a graph data structure.
The system allows users to perform CRUD operations such as adding, displaying, updating, searching, and deleting flight records.
Dynamic memory allocation and file storage are used so that flight data remains stored even after the program exits.


🧠 Data Structure Used
Data Structure Used
The project uses a Graph (Adjacency List Representation) to represent the airline network.
Vertices (Nodes): Airports
Edges: Flight connections between airports
Weights: Ticket prices
The graph is implemented using struct, linked lists, and dynamic memory allocation (malloc, free).
Example:
Chennai → Delhi (5000) → Mumbai (6500)
Delhi   → Mumbai (3000)
Mumbai  → No outgoing flights

In this example, Chennai, Delhi, and Mumbai are vertices, while the arrows represent flight connections with ticket prices as weights.


⚙️ Algorithm Explanation
1. Add Flight (Create)
Enter source airport index.
Enter destination airport index.
Enter ticket price.
Create a new edge using dynamic memory (malloc).
Insert the edge into the adjacency list.
2. Display Flights (Read)
Traverse the adjacency list of each airport.
Display all connected flights and their ticket prices.
3. Update Flight Price (Update)
Search the adjacency list of the source airport.
Locate the destination airport.
Update the ticket price.
4. Delete Flight (Delete)
Traverse the adjacency list.
Find the destination node.
Remove it and release memory using free().
5. Search Flight
Traverse the adjacency list of the source airport.
If destination is found, display the ticket price.
6. File Storage
When the program exits, all flight data is saved in flights.txt.
When the program starts again, the data is loaded from the file.
This ensures permanent storage of flight data.

💻 Compilation Instructions
Compile the Program
gcc main.c -o airline

Run the Program

For Linux/Mac:

./airline


For Windows:

airline.exe









🖥️ Sample Output

<img width="881" height="720" alt="Screenshot 2026-04-04 164411" src="https://github.com/user-attachments/assets/049d6084-4f47-42f0-b429-1f99c670a168" />
<img width="740" height="390" alt="Screenshot 2026-04-04 164422" src="https://github.com/user-attachments/assets/56f92739-75c1-42ef-9ed1-6bb197ad394c" />
<img width="657" height="291" alt="Screenshot 2026-04-04 164440" src="https://github.com/user-attachments/assets/c741c7e1-cdc1-4153-81db-a3738ebded50" />
<img width="897" height="671" alt="Screenshot 2026-04-04 164450" src="https://github.com/user-attachments/assets/39e4edb4-223f-4926-aed7-112bdd8b4586" />
<img width="987" height="671" alt="Screenshot 2026-04-04 164500" src="https://github.com/user-attachments/assets/56ee1513-7abd-4b7d-8ee2-95c04e2cb537" />
<img width="860" height="266" alt="Screenshot 2026-04-04 164510" src="https://github.com/user-attachments/assets/e72197c4-dbbd-459e-bd5a-dfbf9fbb8bc2" />





📌 Conclusion
This project demonstrates the practical use of graph data structures in C programming to model airline flight connections. The system successfully performs CRUD operations and stores flight data permanently using file handling. This project shows how data structures can be applied to solve real-world problems like airline network management.



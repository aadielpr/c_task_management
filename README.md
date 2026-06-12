# Console Task Manager in C — PRD v1.0

## 1. Overview

This project is a simple console-based task management application written in C.

The goal is to build a program that allows users to create, view, update, delete, save, and load tasks from the terminal. This project is designed for beginner C programmers and should be simple enough to build step by step.

This application will later be easier to convert into a GUI application because the task-management logic will already exist.

---

## 2. Product Goal

The application should help users manage a small list of tasks from the command line.

Users should be able to:

- Add new tasks
- View all tasks
- Mark tasks as completed
- Edit existing tasks
- Delete tasks
- Save tasks to a file
- Load saved tasks when the program starts

---

## 3. Target User

The target user is someone who wants a simple personal task tracker.

Example users:

- A student tracking homework
- A beginner programmer tracking learning goals
- A person tracking daily chores
- Someone who wants a lightweight task list without opening a GUI app

---

## 4. Scope

### In Scope for Version 1

Version 1 should include only the basic features needed for a working task manager:

- Main menu
- Add task
- View all tasks
- Mark task as completed
- Edit task
- Delete task
- Save tasks
- Load tasks

### Out of Scope for Version 1

These features should not be built first:

- GUI interface
- User accounts
- Cloud sync
- Notifications
- Calendar integration
- Database storage
- Mobile support
- Advanced recurring tasks

These can be added later after the basic console version works.

---

## 5. Core Features

## Feature 1: Main Menu

### Description

The application should show a menu when it starts.

The menu allows the user to choose what action they want to perform.

### Example Menu

```text
===== TASK MANAGER =====

1. View Tasks
2. Add Task
3. Complete Task
4. Edit Task
5. Delete Task
6. Save Tasks
7. Exit

Choose an option:
```

### Requirements

- The menu should appear after the program starts.
- The menu should appear again after each action is completed.
- The user should enter a number to select an option.
- If the user enters an invalid option, the program should show an error message and display the menu again.

### Example Invalid Input

```text
Invalid option. Please choose a number from 1 to 7.
```

---

## Feature 2: Add Task

### Description

The user should be able to add a new task.

A task is something the user wants to remember or complete.

### Required Task Data

Each task should have:

- Task ID or task number
- Task title
- Completion status

### Example

```text
Enter task title: Finish C assignment
Task added successfully.
```

The task should appear as:

```text
1. [ ] Finish C assignment
```

### Requirements

- The user should be able to type a task title.
- A new task should be added to the task list.
- New tasks should be incomplete by default.
- Empty task titles should not be allowed.
- The app should limit the maximum number of tasks.

### Suggested Limit

```text
Maximum tasks: 100
Maximum title length: 100 characters
```

---

## Feature 3: View Tasks

### Description

The user should be able to view all tasks.

### Example Output

```text
===== TASKS =====

1. [ ] Buy groceries
2. [X] Finish assignment
3. [ ] Read chapter 4
```

### Status Display

```text
[ ] = Incomplete
[X] = Completed
```

### Requirements

- The app should display every task in the task list.
- Each task should show its number.
- Each task should show whether it is completed or incomplete.
- If there are no tasks, the app should show a friendly message.

### Example Empty State

```text
No tasks found. Add a task first.
```

---

## Feature 4: Mark Task as Completed

### Description

The user should be able to mark a task as completed.

### Example Flow

```text
Enter task number to complete: 2
Task marked as completed.
```

Before:

```text
2. [ ] Finish assignment
```

After:

```text
2. [X] Finish assignment
```

### Requirements

- The user should enter the number of the task they want to complete.
- The app should check if the task number exists.
- If the task exists, its status should become completed.
- If the task does not exist, the app should show an error message.
- If the task is already completed, the app may show a message saying it is already completed.

### Example Error

```text
Task not found.
```

---

## Feature 5: Edit Task

### Description

The user should be able to change the title of an existing task.

### Example Flow

```text
Enter task number to edit: 1
Current title: Buy groceries
Enter new title: Buy groceries and soap
Task updated successfully.
```

Before:

```text
1. [ ] Buy groceries
```

After:

```text
1. [ ] Buy groceries and soap
```

### Requirements

- The user should enter the task number they want to edit.
- The app should show the current task title.
- The user should enter a new title.
- Empty new titles should not be allowed.
- The task status should not change when editing the title.

---

## Feature 6: Delete Task

### Description

The user should be able to delete a task.

### Example Flow

```text
Enter task number to delete: 3
Task deleted successfully.
```

Before:

```text
1. [ ] Buy groceries
2. [X] Finish assignment
3. [ ] Read chapter 4
```

After:

```text
1. [ ] Buy groceries
2. [X] Finish assignment
```

### Requirements

- The user should enter the number of the task they want to delete.
- The app should check if the task exists.
- If the task exists, it should be removed from the list.
- Remaining tasks should be re-numbered when displayed.
- If the task does not exist, the app should show an error message.

---

## Feature 7: Save Tasks

### Description

The application should save tasks to a file so tasks are not lost when the program closes.

### File Name

```text
tasks.txt
```

### Example File Format

```text
0|Buy groceries
1|Finish assignment
0|Read chapter 4
```

### Meaning

```text
0 = incomplete
1 = completed
```

### Requirements

- The app should save all tasks to `tasks.txt`.
- Each task should be saved on one line.
- Each line should include the completion status and task title.
- The app should save tasks when the user chooses `Save Tasks`.
- The app should also save tasks automatically when the user exits.

---

## Feature 8: Load Tasks

### Description

The application should load saved tasks when it starts.

### Requirements

- When the app starts, it should check for `tasks.txt`.
- If the file exists, the app should load tasks from it.
- If the file does not exist, the app should start with an empty task list.
- The app should not crash if the file is missing.

### Example

```text
Loaded 3 tasks.
```

or

```text
No saved tasks found. Starting with an empty list.
```

---

## 6. Data Requirements

Each task should store the following data:

| Field | Type | Description |
|---|---|---|
| `title` | string / char array | The task name |
| `completed` | integer | `0` for incomplete, `1` for completed |

### Suggested C Struct

```c
typedef struct {
    int completed;
    char title[100];
} Task;
```

---

## 7. Functional Requirements Summary

| ID | Requirement |
|---|---|
| FR1 | The app must show a main menu. |
| FR2 | The app must allow users to add a task. |
| FR3 | The app must allow users to view all tasks. |
| FR4 | The app must allow users to mark a task as completed. |
| FR5 | The app must allow users to edit a task title. |
| FR6 | The app must allow users to delete a task. |
| FR7 | The app must save tasks to a file. |
| FR8 | The app must load tasks from a file when it starts. |
| FR9 | The app must handle invalid menu input. |
| FR10 | The app must not crash if there are no saved tasks. |

---

## 8. Non-Functional Requirements

## Simplicity

The app should be easy to understand for a beginner C programmer.

## Reliability

The app should not crash when:

- The task file does not exist
- The task list is empty
- The user enters an invalid menu option
- The user enters a task number that does not exist

## Readability

The code should be organized and readable.

Recommended files:

```text
main.c
task.c
task.h
```

## Storage

The app should use a simple text file for storage.

A database is not required for Version 1.

---

## 9. User Flow

```text
Start Program
    ↓
Load saved tasks
    ↓
Show main menu
    ↓
User chooses an option
    ↓
Perform selected action
    ↓
Return to main menu
    ↓
User chooses Exit
    ↓
Save tasks
    ↓
End Program
```

---

## 10. Example Full Session

```text
===== TASK MANAGER =====

1. View Tasks
2. Add Task
3. Complete Task
4. Edit Task
5. Delete Task
6. Save Tasks
7. Exit

Choose an option: 2

Enter task title: Learn structs in C
Task added successfully.

===== TASK MANAGER =====

1. View Tasks
2. Add Task
3. Complete Task
4. Edit Task
5. Delete Task
6. Save Tasks
7. Exit

Choose an option: 1

===== TASKS =====

1. [ ] Learn structs in C

===== TASK MANAGER =====

Choose an option: 3

Enter task number to complete: 1
Task marked as completed.

===== TASKS =====

1. [X] Learn structs in C
```

---

## 11. Suggested Development Steps

## Step 1: Create the Main Menu

Build the menu first.

At this stage, the menu options do not need to work yet.

Goal:

- Show menu
- Read user choice
- Repeat menu until user exits

---

## Step 2: Create the Task Struct

Create a `Task` struct that stores:

- Task title
- Completion status

---

## Step 3: Add Tasks in Memory

Allow users to add tasks while the program is running.

At this stage, tasks do not need to be saved yet.

---

## Step 4: View Tasks

Display all tasks that have been added.

---

## Step 5: Complete Tasks

Allow the user to mark a task as completed.

---

## Step 6: Edit Tasks

Allow the user to update a task title.

---

## Step 7: Delete Tasks

Allow the user to remove a task.

---

## Step 8: Save Tasks to File

Write all tasks to `tasks.txt`.

---

## Step 9: Load Tasks from File

Read tasks from `tasks.txt` when the program starts.

---

## Step 10: Improve Input Validation

Handle bad input such as:

- Invalid menu choices
- Empty task titles
- Task numbers that do not exist
- Too many tasks

---

## 12. Version Plan

## Version 1.0 — Basic Task Manager

Required features:

- Main menu
- Add task
- View tasks
- Complete task
- Edit task
- Delete task
- Save tasks
- Load tasks

---

## Version 1.1 — Better Task Details

Possible features:

- Task description
- Created date
- Due date
- Priority

---

## Version 1.2 — Organization Features

Possible features:

- Categories
- Search tasks
- Filter by completed/incomplete
- Sort by title or priority

---

## Version 2.0 — GUI Preparation

Possible improvements:

- Separate task logic from menu logic
- Keep task operations in `task.c`
- Keep console UI in `main.c`
- Make the code easier to reuse in a GUI app later

---

## 13. Future Feature Ideas

These are not required for the first version.

## Priority

Tasks can have priority levels:

```text
LOW
MEDIUM
HIGH
```

Example:

```text
1. [ ] [HIGH] Submit assignment
```

## Due Date

Tasks can have deadlines.

Example:

```text
1. [ ] Submit report — Due: 2026-06-20
```

## Categories

Tasks can belong to categories.

Example categories:

- Work
- School
- Personal
- Health

## Search

Users can search for tasks by keyword.

## Filter

Users can filter tasks by:

- All tasks
- Completed tasks
- Incomplete tasks
- High priority tasks

## Sort

Users can sort tasks by:

- Title
- Completion status
- Priority
- Due date

## Statistics

The app can show task statistics.

Example:

```text
Total tasks: 10
Completed: 4
Incomplete: 6
Completion rate: 40%
```

---

## 14. Success Criteria

The project is successful when:

- A user can add a task
- A user can view all tasks
- A user can complete a task
- A user can edit a task
- A user can delete a task
- Tasks are saved after exiting
- Tasks are loaded when restarting the app
- The program does not crash from common invalid input

---

## 15. Learning Objectives

By completing this project, you should understand:

- How to use structs
- How to use arrays
- How to work with strings
- How to write functions
- How to split code into multiple files
- How to use header files
- How to read and write files
- How to validate user input
- How to organize a small C project

---

## 16. Recommended Project Structure

```text
console-task-manager/
│
├── main.c
├── task.c
├── task.h
├── tasks.txt
└── README.md
```

### main.c

Handles:

- Program start
- Main menu
- User input
- Calling task functions

### task.c

Handles:

- Adding tasks
- Viewing tasks
- Completing tasks
- Editing tasks
- Deleting tasks
- Saving tasks
- Loading tasks

### task.h

Contains:

- Task struct definition
- Function declarations
- Constants

### tasks.txt

Stores saved task data.

---

## 17. Notes for Beginner Developers

Start small.

Do not build all features at once.

Recommended order:

1. Make the menu work.
2. Add one task in memory.
3. Show all tasks.
4. Complete a task.
5. Delete a task.
6. Edit a task.
7. Save to file.
8. Load from file.
9. Clean up and improve input handling.

Once Version 1 works, you can start thinking about GUI libraries like GTK.

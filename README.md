# Scrivener

Scrivener is a *command-line* task management tool that allows you to *create, view, update, and delete tasks*. It stores tasks in a binary file and provides a simple interface for managing your tasks.

## Features

- Add new tasks with a name, date, and priority.
- View all tasks.
- Update existing tasks.
- Delete tasks.

## Requirements

- Python 3.x
- GCC
- Cython

## Installation

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd scrivener
    ```

2. Install the required Python packages:
    ```sh
    pip install -r requirements.txt
    ```

    You may need to create a virtual environment to install
    the python packages. If you receive an error when trying
    to `pip install -r requirements.txt`. Create a venv with:

    ```sh
        python3 -m venv .venv
    ```

    Then, source it:

    ```sh
        source .venv/bin/activate
    ```

3. Run the installation script:
    ```sh
    ./install.sh
    ```

## Usage

```sh
scrivener [OPTION] [ARGS...]

```

## Examples

- Add a new task:

```sh
    scrivener -i "Buy groceries" "12/28/2024" 1
```

- View all tasks:

```sh
    scrivener -v
```

- Update a task:

```sh
    scrivener -u "Buy groceries" "Buy fruits" "12/29/2024" 1
```

- Delete a task:

```sh
    scrivener -d "Buy groceries"
```

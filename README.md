# Dining Philosophers

###### _Three solves for the classical Dining Philosophers problem_

#### There are three different solutuions to the task:

- philo_one: philosophers as #####threads, forks as #####mutexes
- philo_two: philosophers as threads, forks as semaphores
- philo_three: philosophers as processes, forks as semaphores

## Usage

Run `make` inside the repository's directory to create a 
library file. Now the `libasm.a` library at your disposal.

Run `make test` creates binary file using `libasm.a` to test it.

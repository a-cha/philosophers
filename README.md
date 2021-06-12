# Dining Philosophers

###### _Small library written on Assembly language_

#### There are three different solutuions to the task:

- philo_one: philosophers as _threads_, forks as _mutexes_
- philo_two: philosophers as threads, forks as semaphores
- philo_three: philosophers as processes, forks as semaphores

## Usage

Run `make` inside the repository's directory to create a 
library file. Now the `libasm.a` library at your disposal.

Run `make test` creates binary file using `libasm.a` to test it.

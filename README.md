# Dining Philosophers

#### There are three different solutuions to the task:

- philo_one: philosophers as _**threads**_, forks as _**mutexes**_
- philo_two: philosophers as _**threads**_, forks as _**semaphores**_
- philo_three: philosophers as _**processes**_, forks as _**semaphores**_

## Usage

Run `make` inside the philo_one/two/three directory to create a 
binary file.
Run the program like `./philo_one 5 600 200 100 10`, where specified parameters are:
- `5` - number_of_philosophers: is the number of philosophers and also the number of forks
- `600` - time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal, he dies
- `200` - time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat
- `100` - time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping
- `10` - number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher

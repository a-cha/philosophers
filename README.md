# Dining Philosophers

The purpose of the project is to solve the classical [Dining Philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

In the task's context philosophers considered as processes and forks as resources. The main aim of the task is to avoid the deadlock.

#### There are three different solutuions:

- philo_one - philosophers as _**threads**_, forks as _**mutexes**_
- philo_two - philosophers as _**threads**_, forks as _**semaphores**_
- philo_three - philosophers as _**processes**_, forks as _**semaphores**_

## Usage

Run `make` inside the philo_one/two/three directory to create a 
binary file.

Run the program like `./philo_one 5 600 200 100 10` with some necessary arguments.

<details>
    <summary>
        What is arguments?
    </summary>
    <br/>
    <ol>
        <li>Number of philosophers (5) - is the number of philosophers and also the number of forks</li>
        <li>Time to die (600) - is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal, he dies</li>
        <li>Time to eat (200) - is in milliseconds and is the time it takes for a philosopher to eat</li>
        <li>Time to sleep (100) - is in milliseconds and is the time the philosopher will spend sleeping</li>
        <li>Number of times each philosopher must eat (10) - argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher</li>
    </ol>
</details>

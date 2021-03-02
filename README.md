# timelib
Timelib is a c library, providing time functions for date handling. 

## Usage
```c
#include "time.h"

...

struct date date;
input_date(&date);
#input

isLeapYear(2000);
#output: true

date.day = 25;
date.month = 5;
date.year = 2020;
day_of_the_year(date);
#output: 142
```

## License
[MIT](https://github.com/smallonotation/timelib/blob/master/LICENSE)

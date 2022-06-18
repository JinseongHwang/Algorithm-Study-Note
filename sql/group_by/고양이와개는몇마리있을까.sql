select animal_type, count(1)
from animal_ins
group by animal_type
order by animal_type;
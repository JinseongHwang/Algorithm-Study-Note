select name, count(1)
from animal_ins
group by name
having count(name)>=2
order by name asc;
select outs.animal_id, outs.name
from animal_ins as ins
join animal_outs as outs
where ins.animal_id=outs.animal_id
order by (outs.datetime - ins.datetime) desc
limit 2;
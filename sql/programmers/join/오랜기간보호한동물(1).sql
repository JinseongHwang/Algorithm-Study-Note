select ins.name, ins.datetime
from animal_ins as ins
left outer join animal_outs as outs
on ins.animal_id = outs.animal_id
where outs.animal_id is null
order by ins.datetime asc
limit 3;
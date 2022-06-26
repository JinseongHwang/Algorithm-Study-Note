-- sex_upon_intake  ->  sex_upon_outcome
-- Intact Male  ->  Neutered Male
-- Intact Female    ->  Spayed Female

select ins.animal_id, ins.animal_type, ins.name
from animal_ins as ins
inner join animal_outs as outs
    on ins.animal_id = outs.animal_id
where ins.sex_upon_intake like "Intact%"
    and outs.sex_upon_outcome not like "Intact%"
order by ins.animal_id asc;
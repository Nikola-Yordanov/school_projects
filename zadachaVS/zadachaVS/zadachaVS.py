
name_id_dict = {
'Tisho': 1,
'Pesho': 2,
'Mariika': 3,
'Ivancho': 4,
'Katinka': 5,
'Borimechkata': 7,
}
id_ages_dict = {
1: 23,
2: 15,
3: 16,
4: 17,
5: 9,
7: 18,
}
id_sex_dict = {
1: 'male',
2: 'male',
3: 'female',
4: 'male',
5: 'female',
7: 'male',
}


# def classify_by_avg_age_per_sex(name_id_dict, id_age_dict, id_sex_dict):



def calculate_avg_age_per_sex(id_sex_dict, id_ages_dict):
    sex_age_male = []
    sex_age_female = []
    for key, value in id_sex_dict.items():
        if value == 'male':
            for key1 in id_ages_dict.keys():
                x = id_ages_dict.get(key1)
                sex_age_male.append(x)
        elif value == 'female':
            for key2 in id_ages_dict.keys():
                y = id_ages_dict.get(key2)
                sex_age_female.append(y)


calculate_avg_age_per_sex(id_sex_dict, id_ages_dict)
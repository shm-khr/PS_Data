# coding=utf-8
from math import sqrt, fsum


def inner_product(vect1, vect2):
    return math.fsum([(v1_el*v2_el) for v1_el, v2_el in zip(vect1, vect2)])


def vector_abs(vect):
    return sqrt(sum([element**2 for element in vect]))


def direction_unit_vector(p_from, p_to):
    d_vector = [(xt - xf) for xt, xf in zip(p_to, p_from)]
    d_u_vector = [element/vector_abs(d_vector) for element in d_vector]
    return d_u_vector


def projection(origin, line_from, line_to):
    direction_unit = direction_unit_vector(line_from, line_to)
    origin_d_vector = [(org-lf) for org, lf in zip(origin, line_from)]
    inject_dist = inner_product(direction_unit, origin_d_vector)
    on_line_vect = [inject_dist*element for element in direction_unit]
    return [olv_el + lf_el for olv_el, lf_el in zip(on_line_vect, line_from)]


def reflection(origin, line_from, line_to):
    mid_point = projection(origin, line_from, line_to)
    direction = [2*(mp_el - or_el) for mp_el, or_el in zip(mid_point, origin)]
    reflected = [(dr_el + or_el) for dr_el, or_el in zip(direction, origin)]
    return reflected


if __name__ == '__main__':
    xy_list = list(map(int, input().split()))
    p1_list = xy_list[:2]
    p2_list = xy_list[2:]
    Q = int(input())

    for i in range(Q):
        p_list = list(map(int, input().split()))
        x_list = reflection(p_list, p1_list, p2_list)
        print(' '.join(map(str, x_list)))


from .persona_role_play import PersonaRolePlay
from .textual_injection import TextualInjection
from .control_flow_interleaving import ControlFlowInterleaving
from .identifier_shadowing import IdentifierShadowing

ALL_ATTACKS = [
    PersonaRolePlay(),
    TextualInjection(),
    ControlFlowInterleaving(),
    IdentifierShadowing(),
]

ATTACK_MAP = {a.name: a for a in ALL_ATTACKS}

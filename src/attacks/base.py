from abc import ABC, abstractmethod
from typing import Literal

Language = Literal["python", "java", "cpp", "javascript"]
SUPPORTED_LANGUAGES: tuple = ("python", "java", "cpp", "javascript")


class Attack(ABC):
    """
    Abstract base class for all academic jailbreaking attack strategies.

    Each attack takes a clean student code submission and returns a poisoned
    version with an adversarial injection embedded. The returned code must:
      - Preserve all original code lines
      - Be syntactically valid in the target language
      - Produce identical runtime output to the original (for CFI and IS)

    Attack surface taxonomy:
      "social_compliance"   -- Categories 1-2: exploits RLHF helpfulness fine-tuning
      "syntax_semantics_gap" -- Categories 3-4: exploits the gap between what the
                                compiler executes and what the LLM tokenizer reads
    """

    name: str
    attack_surface: str

    @abstractmethod
    def inject(self, code: str, language: Language) -> str:
        """
        Apply the adversarial injection to a clean code submission.

        Args:
            code:     The original student submission as a string.
            language: One of "python", "java", "cpp", "javascript".

        Returns:
            The poisoned submission as a string.
        """
        ...

    def verify_injection(self, original: str, injected: str) -> bool:
        """Returns True if the injection produced a different string."""
        return injected != original

    def __repr__(self) -> str:
        return f"{self.__class__.__name__}(surface={self.attack_surface})"

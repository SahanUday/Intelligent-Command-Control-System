import from mtllm.llms { Gemini }

# Setup Gemini Flash 2.5 LLM
glob llm = Gemini(model_name="gemini-2.5-flash");

"""
extract the command from user_input, also understand sinhala, singlish or anyother language of user given.
extract command should be according to the given template
template of extract command = {led: _GREEN/YELLOW/BLUE_, command: _ON/OFF_, delay: _delay time in seconds_}
"""

def generate_command(user_input: str) -> dict byllm(); # Gives helpful hint

# Walker that calls the LLM and stores the result
walker interpret_voice {
    has user_input: str;

    obj __specs__ {
        static has methods: list = ["post"];   # Allow POST requests
        static has auth: bool = False;         # No auth required
    }

    can generate with `root entry {

        result = generate_command(self.user_input);
        # print(result["command"], result["delay"]);
        report {
            "led": result["led"],
            "command": result["command"],
            "delay": result["delay"]
        };
    }
}


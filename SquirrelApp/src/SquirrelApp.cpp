#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"

#include "Squirrel.h"

std::string str;

class AppLayer : public Walnut::Layer
{
public:
	virtual void OnAttach() override {
		str = Squirrel::File::loadFile("config.save");
	}

	virtual void OnDetach() override {
		Squirrel::File::writeFile("config.save", str);
	}

	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "SquirrelApp Example";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<AppLayer>();
	app->SetMenubarCallback([app]()
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					app->Close();
				}
				ImGui::EndMenu();
			}
		});
	return app;
}

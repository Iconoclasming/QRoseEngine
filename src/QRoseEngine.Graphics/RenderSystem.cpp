#include <QRoseEngine.Graphics/RenderSystem.hpp>

#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

RenderSystem::RenderSystem(Ptr<Render> pRender, Ptr<EntitiesComponentsService> pEntitiesComponentsService)
	: render(pRender), ecs(pEntitiesComponentsService)
{
	if(pRender == nullptr)
	{
		throw std::invalid_argument("pRender == nullptr");
	}
	if(pEntitiesComponentsService == nullptr)
	{
		throw std::invalid_argument("pEntitiesComponentsService == nullptr");
	}
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double millisecondsElapsed)
{
	render->ClearView();
	render->BeginDrawing();

	Matrix4x4 viewMatrix;
	viewMatrix = viewMatrix.Translate(Vector3(0.5f, 0.0f, -3.0f));

	Ptr<Manager<MeshComponent>> meshComponentsManager = ecs->GetManager<MeshComponent>();
	const std::vector<std::pair<Handle, MeshComponent>>& entitiesWithMeshes = meshComponentsManager->GetAllComponents();
	std::vector<std::tuple<MeshComponent, TransformationComponent>> toDraw;
	toDraw.reserve(entitiesWithMeshes.size());
	Ptr<Manager<TransformationComponent>> transformComponentsManager = ecs->GetManager<TransformationComponent>();
	for (auto& entityWithMesh : entitiesWithMeshes)
	{
		if (transformComponentsManager->Contains(entityWithMesh.first))
		{
			toDraw.push_back(std::make_tuple(entityWithMesh.second,
				transformComponentsManager->GetComponent(entityWithMesh.first)));
		}
	}
	render->SetViewMatrix(viewMatrix);
	for (const auto& toDrawTuple : toDraw)
	{
		const MeshComponent& meshComponent = std::get<0>(toDrawTuple);
		const TransformationComponent& transform = std::get<1>(toDrawTuple);
		Matrix4x4 modelMatrix;
		modelMatrix = modelMatrix.Translate(transform.position);
		modelMatrix = modelMatrix.Rotate(transform.rotation);
		modelMatrix = modelMatrix.Scale(transform.scale);
		render->DrawMesh(meshComponent.meshId, modelMatrix);
	}

	render->Present();
}
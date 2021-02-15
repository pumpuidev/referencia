m = zeros(1,5);
colors = lines(6);
ax = axes('Position',[0 0 1 1]);
patch(pts1(1,:),pts1(2,:),m,'FaceColor',colors(1,:));
axis off
axis equal